#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int dp[1001][2][3];
const int MOD = 1000000; //
int main() {
    fastio;

    int n;
    cin >> n;
    dp[1][0][0] = 1;
    dp[1][1][0] = 1;
    dp[1][0][1] = 1;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 3; ++k) {
                dp[i+1][j][0] += dp[i][j][k];
                if (j == 0) dp[i+1][j+1][0] += dp[i][j][k];
                if (k <= 1) dp[i+1][j][k+1] += dp[i][j][k];
            }
        }
        
//        dp[i+1][0][0] += dp[i][0][0];
//        dp[i+1][1][0] += dp[i][0][0];
//        dp[i+1][0][1] += dp[i][0][0];
//
//        dp[i+1][0][0] += dp[i][0][1];
//        dp[i+1][1][0] += dp[i][0][1];
//        dp[i+1][0][2] += dp[i][0][1];
//
//        dp[i+1][0][0] += dp[i][0][2];
//        dp[i+1][1][0] += dp[i][0][2];
//
//        dp[i+1][1][0] += dp[i][1][0];
//        dp[i+1][1][1] += dp[i][1][0];
//
//        dp[i+1][1][0] += dp[i][1][1];
//        dp[i+1][1][2] += dp[i][1][1];
//
//        dp[i+1][1][0] += dp[i][1][2];
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 3; ++k) {
                dp[i+1][j][k] %= MOD;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            ans += dp[n][i][j];
        }
    }
    ans %= MOD;
    cout << ans;
}