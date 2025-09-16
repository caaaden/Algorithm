#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

#define fastio ios::sync_with_stdio(0), cin.tie(0)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define X first
#define Y second
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define pb push_back

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using psi = pair<string, int>;
using piii = pair<int, pii>;
using piiii = pair<pii, pii>;

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

constexpr int dx[4] = {1, -1, 0, 0};
constexpr int dy[4] = {0, 0, 1, -1};
constexpr int bit = 9;
const long long MOD = 1e9 + 7;
const int MAX = 1e9;

int main(){
    fastio;

    int n, q; cin >> n >> q;
    vector<int> p(n+1);
    for (int i = 2; i <= n; ++i) {
        int a; cin >> a;
        p[i] = a;
    }
    vector<piii> queries(n+q-1);
    for (int i = 0; i < n+q-1; ++i) {
        int x; cin >> x;
        if (x == 0) {
            int b; cin >> b;
            queries[i] = {x, {b, 0}};
        } else {
            int c, d; cin >> c >> d;
            queries[i] = {x, {c, d}};
        }
    }
    reverse(all(queries));
    vector<int> ans;
    ans.reserve(q);
    vector<int> parent(n+1);
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
    }
    function<int(int)> find = [&](int a) {
        if (a == parent[a]) return a;
        return parent[a] = find(parent[a]);
    };
    auto merge = [&](int a, int b) {
        a = find(a), b = find(b);
        if (a > b) parent[a] = b;
        else parent[b] = a;
    };
    for (int i = 0; i < n+q-1; ++i) {
        if (queries[i].X == 0) {
            int b = queries[i].Y.X;
            merge(b, p[b]);
        } else {
            auto [c, d] = queries[i].Y;
            if (find(c) == find(d)) ans.push_back(1);
            else ans.push_back(0);
        }
    }
    reverse(all(ans));
    for (auto& e : ans) {
        cout << (e ? "YES" : "NO") << '\n';
    }
}