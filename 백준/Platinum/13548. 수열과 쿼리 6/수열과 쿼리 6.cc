#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0);
#define all(v) v.begin(), v.end()
#define X first
#define Y second
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using piii = pair<int, pii>;
using piiii = pair<pii, pii>;

int cnt[100001];
int cnt2[100001];
int main() {
    fastio;

    int n;
    cin >> n;
    int sq = sqrt(n);
    vector<int> v(n+1);
    for (int i = 1; i <= n; ++i) cin >> v[i];
    int cntMax = 0;
    int m;
    cin >> m;
    vector<piii> query(m);
    vector<ll> ans(m);
    for (int i = 0; i < m; ++i) {
        int s, e;
        cin >> s >> e;
        query[i] = {i, {s, e}};
    }
    sort(all(query), [&sq](const piii& a, const piii& b) {
        int aa = a.Y.X / sq;
        int bb = b.Y.X / sq;
        if (aa != bb) return aa < bb;
        return (aa & 1) ? a.Y.Y < b.Y.Y : a.Y.Y > b.Y.Y;
    });
    int s = query[0].Y.X, e = query[0].Y.Y;
    cnt2[0] = n;
    for (int i = s; i <= e; ++i) {
        cnt2[cnt[v[i]]]--;
        cnt[v[i]]++;
        cnt2[cnt[v[i]]]++;
        cntMax = max(cntMax, cnt[v[i]]);
    }
    ans[query[0].X] = cntMax;
    for (int i = 1; i < m; ++i) {
        int qs = query[i].Y.X;
        int qe = query[i].Y.Y;
        while (e < qe) {
            ++e;
            cnt2[cnt[v[e]]]--;
            cnt[v[e]]++;
            cnt2[cnt[v[e]]]++;
            cntMax = max(cntMax, cnt[v[e]]);
        }
        while (s > qs) {
            --s;
            cnt2[cnt[v[s]]]--;
            cnt[v[s]]++;
            cnt2[cnt[v[s]]]++;
            cntMax = max(cntMax, cnt[v[s]]);
        }
        while (s < qs) {
            cnt2[cnt[v[s]]]--;
            if (!cnt2[cnt[v[s]]] && cnt[v[s]] == cntMax) cntMax--;
            cnt[v[s]]--;
            cnt2[cnt[v[s]]]++;
            ++s;
        }
        while (e > qe) {
            cnt2[cnt[v[e]]]--;
            if (!cnt2[cnt[v[e]]] && cnt[v[e]] == cntMax) cntMax--;
            cnt[v[e]]--;
            cnt2[cnt[v[e]]]++;
            --e;
        }
        ans[query[i].X] = cntMax;
    }
    for (auto& e : ans) cout << e << '\n';
}