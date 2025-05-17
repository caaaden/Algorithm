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

int main(){
    fastio;

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (auto& e : v) cin >> e;
        vector<bool> check(n+1);
        reverse(all(v));
        vector<int> ans;
        ans.reserve(n);
        for (auto& e : v) {
            int cnt = 0;
            bool found = false;
            for (int i = 1; i <= n; ++i) {
                if (check[i]) continue;
                cnt++;
                if (cnt-1 == e) {
                    ans.push_back(i);
                    check[i] = true;
                    found = true;
                    break;
                }
            }
            if (found) continue;
            break;
        }
        if (ans.size() != n) {
            cout << "IMPOSSIBLE" << '\n';
        } else {
            reverse(all(ans));
            for (auto& e : ans) cout << e << ' ';
            cout << '\n';
        }
    }
}