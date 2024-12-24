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
    ll res = 0;
    vector<int> tree(n+1);
    auto sum = [&tree, &n](int i) {
        if (i < 1) return 0;
        if (i > n) i = n;
        int ret = 0;
        while (i > 0) {
            ret += tree[i];
            i -= (i & -i);
        }
        return ret;
    };
    auto update = [&tree](int i, int diff) {
        while (i < tree.size()) {
            tree[i] += diff;
            i += (i & -i);
        }
    };
    auto add = [&v, &n, &sum, &update, &res](int idx, bool isLeft) {
        int val = v[idx];
        if (isLeft) res += sum(val-1);
        else res += sum(n) - sum(val);
        update(val, 1);
    };
    auto remove = [&v, &n, &sum, &update, &res](int idx, bool isLeft) {
        int val = v[idx];
        update(val, -1);
        if (isLeft) res -= sum(val-1);
        else res -= sum(n) - sum(val);
    };
    auto getAnswer = [&res]() {
        return res;
    };
    int s = query[0].Y.X, e = s - 1;
    for (int i = 0; i < m; ++i) {
        const int qs = query[i].Y.X;
        const int qe = query[i].Y.Y;
        while (e < qe) add(++e, false);
        while (s > qs) add(--s, true);
        while (e > qe) remove(e--, false);
        while (s < qs) remove(s++, true);
        ans[query[i].X] = getAnswer();
    }
    for (const auto& e : ans) cout << e << '\n';
}