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
        int x; cin >> x;
        p[i] = x;
    }
    vector<set<int>> S(n+1);
    for (int i = 1; i <= n; ++i) {
        int c; cin >> c;
        S[i].insert(c);
    }
    vector<pii> queries(n+q-1);
    for (auto& [a, b] : queries) cin >> a >> b;
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
        if (S[a].size() < S[b].size()) swap(S[a], S[b]);
        S[a].merge(S[b]);
        if (a > b) {
            parent[a] = b;
            swap(S[a], S[b]);
        } else {
            parent[b] = a;
        }
    };
    for (auto& [a, b] : queries) {
        if (a == 1) {
            merge(b, p[b]);
        } else {
            ans.push_back(S[find(b)].size());
        }
    }
    reverse(all(ans));
    for (auto& e : ans) cout << e << '\n';
}