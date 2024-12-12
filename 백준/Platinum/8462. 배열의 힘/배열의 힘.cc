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

int main() {
    fastio;

    int n, m;
    cin >> n >> m;
    int sq = sqrt(n);
    vector<int> v(n+1);
    vector<int> cnt(1e6+1);
    for (int i = 1; i <= n; ++i) cin >> v[i];
    vector<piii> query(m);
    vector<ll> ans(m);
    for (int i = 0; i < m; ++i) {
        int s, e;
        cin >> s >> e;
        query[i] = {i, {s, e}};
    }
    sort(all(query), [&sq](const piii& a, const piii& b) {
        int aa = a.Y.X >> 9;
        int bb = b.Y.X >> 9;
        if (aa != bb) return aa < bb;
        return (aa & 1) ? a.Y.Y < b.Y.Y : a.Y.Y > b.Y.Y;
    });
    ll res = 0;
    auto add = [&v, &cnt, &res](int idx) {
        ll val = v[idx];
        ll count = cnt[val];
        res += val * (2 * count + 1);
        cnt[val]++;
    };
    auto sub = [&v, &cnt, &res](int idx) {
        ll val = v[idx];
        ll count = cnt[val];
        res -= val * (2 * count - 1);
        cnt[val]--;
    };
    int s = query[0].Y.X, e = query[0].Y.Y;
    for (int i = s; i <= e; ++i) add(i);
    ans[query[0].X] = res;
    for (int i = 1; i < m; ++i) {
        int qs = query[i].Y.X;
        int qe = query[i].Y.Y;
        while (e < qe) {
            ++e;
            add(e);
        }
        while (s > qs) {
            --s;
            add(s);
        }
        while (e > qe) {
            sub(e);
            --e;
        }
        while (s < qs) {
            sub(s);
            ++s;
        }
        ans[query[i].X] = res;
    }
    for (auto& e : ans) cout << e << '\n';
}