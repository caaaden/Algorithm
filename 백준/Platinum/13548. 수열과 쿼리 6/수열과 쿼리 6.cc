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
//    vector<piii> query(m);
    piii query[m];
    vector<ll> ans(m);
    for (int i = 0; i < m; ++i) {
        int s, e;
        cin >> s >> e;
        query[i] = {i, {s, e}};
    }
    sort(query, query+m, [&sq](const piii& a, const piii& b) {
        if (a.Y.X/sq == b.Y.X/sq) return a.Y.Y < b.Y.Y;
        return a.Y.X/sq < b.Y.X/sq;
    });
    int s = query[0].Y.X, e = query[0].Y.Y;
    cnt2[0] = n;
    for (int i = s; i <= e; ++i) {
        cnt2[cnt[v[i]]]--;
        cnt[v[i]]++;
        cnt2[cnt[v[i]]]++;
        if (cntMax < cnt[v[i]]) cntMax = cnt[v[i]];
    }
    ans[query[0].X] = cntMax;
    for (int i = 1; i < m; ++i) {
        int qs = query[i].Y.X;
        int qe = query[i].Y.Y;
        while (e < qe) {
            ++e;
            int num = v[e];
            cnt2[cnt[num]]--;
            cnt[num]++;
            cnt2[cnt[num]]++;
            if (cntMax < cnt[num]) cntMax = cnt[num];
        }
        while (s > qs) {
            --s;
            int num = v[s];
            cnt2[cnt[num]]--;
            cnt[num]++;
            cnt2[cnt[num]]++;
            if (cntMax < cnt[num]) cntMax = cnt[num];
        }
        while (s < qs) {
            int num = v[s];
            cnt2[cnt[num]]--;
            if (!cnt2[cntMax]) cntMax--;
            cnt[num]--;
            cnt2[cnt[num]]++;
            ++s;
        }
        while (e > qe) {
            int num = v[e];
            cnt2[cnt[num]]--;
            if (!cnt2[cntMax]) cntMax--;
            cnt[num]--;
            cnt2[cnt[num]]++;
            --e;
        }
        ans[query[i].X] = cntMax;
    }
    for (auto& e : ans) cout << e << '\n';
}