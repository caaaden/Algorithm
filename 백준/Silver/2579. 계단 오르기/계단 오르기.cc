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

//template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T, typename Compare = less<T>>
using ordered_set = tree<T, null_type, Compare, rb_tree_tag, tree_order_statistics_node_update>;

constexpr int dx[4] = {1, -1, 0, 0};
constexpr int dy[4] = {0, 0, 1, -1};
constexpr int bit = 9;
const long long MOD = 1e9 + 7;
const long long MOD2 = 1e9 + 9;
const int MAX = 1e9;

int main(){
    fastio;

    int n; cin >> n;
    vector<int> v(n+1);
    for (int i = 1; i <= n; ++i) cin >> v[i];
    if (n == 1) {
        cout << v[1];
        return 0;
    }
    if (n == 2) {
        cout << v[1] + v[2];
        return 0;
    }
    vector<vector<int>> dp(n+1, vector<int>(2));
    dp[1][0] = v[1], dp[1][1] = v[1];
    dp[2][0] = v[1] + v[2], dp[2][1] = v[2];
    for (int i = 3; i <= n; ++i) {
        dp[i][0] = dp[i-1][1] + v[i];
        dp[i][1] = max(dp[i-2][0], dp[i-2][1]) + v[i];
    }
    cout << max(dp[n][0], dp[n][1]);
}