#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define fastio ios::sync_with_stdio(0), cin.tie(0);
#define all(v) v.begin(), v.end()
#define X first
#define Y second
#define rep(i, a, b) for (int i = a; i < b; ++i)

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using piii = pair<int, pii>;
using piiii = pair<pii, pii>;

template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

constexpr int dx[4] = {1, -1, 0, 0};
constexpr int dy[4] = {0, 0, 1, -1};
constexpr int bit = 9;

int main() {
    fastio;

    int n, m;
    cin >> n >> m;
    vector<int> v(n+1);
    for (int i = 1; i <= n; ++i) cin >> v[i];
    vector<int> tmp = v;
    sort(tmp.begin()+1, tmp.end());
    tmp.erase(unique(tmp.begin()+1, tmp.end()), tmp.end());
    for (int i = 1; i <= n; ++i) v[i] = lower_bound(tmp.begin()+1, tmp.end(), v[i]) - tmp.begin();
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
    int res = 0;
    vector<int> cnt(n+1);
    auto add = [&v, &cnt, &res](int idx) {
        int val = v[idx];
        if (cnt[val] == 2) res--;
        cnt[val]++;
        if (cnt[val] == 2) res++;
    };
    auto remove = [&v, &cnt, &res](int idx) {
        int val = v[idx];
        if (cnt[val] == 2) res--;
        cnt[val]--;
        if (cnt[val] == 2) res++;
    };
    auto getAnswer = [&res]() {
        return res;
    };
    int s = query[0].Y.X, e = s - 1;
    for (int i = 0; i < m; ++i) {
        const int qs = query[i].Y.X;
        const int qe = query[i].Y.Y;
        while (e < qe) add(++e);
        while (s > qs) add(--s);
        while (e > qe) remove(e--);
        while (s < qs) remove(s++);
        ans[query[i].X] = getAnswer();
    }
    for (const auto& e : ans) cout << e << '\n';
}