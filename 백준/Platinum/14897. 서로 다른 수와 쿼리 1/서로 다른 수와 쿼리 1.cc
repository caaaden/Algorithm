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

constexpr int bit = 9;
int main() {
    fastio;

    int n;
    cin >> n;
    vector<int> v(n+1);
    for (int i = 1; i <= n; ++i) cin >> v[i];
    vector<int> tmp = v;
    sort(tmp.begin()+1, tmp.end());
    tmp.erase(unique(tmp.begin()+1, tmp.end()), tmp.end()); // 중복 제거
    for (int i = 1; i <= n; ++i) v[i] = lower_bound(tmp.begin()+1, tmp.end(), v[i]) - tmp.begin();
    int m;
    cin >> m;
    vector<int> cnt(1e6+1);
    vector<piii> query(m);
    vector<ll> ans(m);
    for (int i = 0; i < m; ++i) {
        int s, e;
        cin >> s >> e;
        query[i] = {i, {s, e}};
    }
    sort(all(query), [](const piii& a, const piii& b) {
        int aa = a.Y.X >> bit;
        int bb = b.Y.X >> bit;
        if (aa != bb) return aa < bb;
        return (aa & 1) ? a.Y.Y < b.Y.Y : a.Y.Y > b.Y.Y;
    });
    ll cntDistinct = 0;
    auto add = [&v, &cnt, &cntDistinct](int idx) {
        if (!cnt[v[idx]]) cntDistinct++;
        cnt[v[idx]]++;
    };
    auto sub = [&v, &cnt, &cntDistinct](int idx) {
        cnt[v[idx]]--;
        if (!cnt[v[idx]]) cntDistinct--;
    };
    int s = query[0].Y.X, e = s - 1;
    for (int i = 0; i < m; ++i) {
        const int qs = query[i].Y.X;
        const int qe = query[i].Y.Y;
        while (e < qe) add(++e);
        while (s > qs) add(--s);
        while (e > qe) sub(e--);
        while (s < qs) sub(s++);
        ans[query[i].X] = cntDistinct;
    }
    for (const auto& e : ans) cout << e << '\n';
}