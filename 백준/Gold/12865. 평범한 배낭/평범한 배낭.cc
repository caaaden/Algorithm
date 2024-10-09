#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define all(v) (v).begin(), (v).end()
using namespace __gnu_pbds;
using namespace std;
using pii = pair<int, int>;
using i64 = long long;
typedef tree<i64, null_type, less<i64>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main() {
    fastio;

    int n, k;
    cin >> n >> k;
    vector<int> w(n+1), v(n+1);
    for (int i = 1; i <= n; ++i) cin >> w[i] >> v[i];
//    vector<vector<int>> dp(n+1, vector<int>(k+1));
//    for (int i = 1; i <= n; ++i) {
//        for (int j = 1; j <= k; ++j) {
//            if (w[i] > j) dp[i][j] = dp[i-1][j];
//            else dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + v[i]);
//        }
//    }
//    cout << dp[n][k];

    vector<vector<int>> dp(2, vector<int>(k+1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            if (w[i] > j) dp[1][j] = dp[0][j];
            else dp[1][j] = max(dp[0][j], dp[0][j-w[i]] + v[i]);
        }
        swap(dp[0], dp[1]);
    }
    cout << dp[0][k];
}