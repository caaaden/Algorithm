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

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

constexpr int dx[4] = {1, -1, 0, 0};
constexpr int dy[4] = {0, 0, 1, -1};
constexpr int bit = 9;
const long long MOD = 1e9 + 7;
const int MAX = 1e9;

int main(){
    fastio;

    int n; cin >> n;
    string m; cin >> m;
    vector<int> v(n+1);
    for (int i = 1; i <= n; ++i) cin >> v[i];
    vector<vector<vector<int>>> groups(n+1);
    vector<int> vis(n+1);
    for (int i = 1; i <= n; ++i) {
        if (vis[i]) continue;
        vis[i] = 1;
        int now = i;
        vector<int> perms;
        perms.push_back(now);
        while (v[now] != i) {
            now = v[now];
            perms.push_back(now);
            vis[now] = 1;
        }
        groups[perms.size()].push_back(perms);
    }
    vector<int> ans(n+1);
    for (int i = 1; i <= n; ++i) {
        if (groups[i].empty()) continue;
//        for (auto& group : groups[i]) {
//            for (auto& e : group) cout << e << ' ';
//            cout << '\n';
//        }
        int r = 0;
        for (auto& d : m) {
            r = (r * 10 + (d - '0')) % i;
        }
//        cout << r << '\n';
        for (auto& group : groups[i]) {
            int idx = group[0];
            for (int j = 0; j < i; ++j) {
                ans[idx] = group[(j+r)%i];
                idx = v[idx];
            }
        }
    }
    for (int i = 1; i <= n; ++i) cout << ans[i] << ' ';
}