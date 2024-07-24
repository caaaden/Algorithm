#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int dp[1001][2][3];
const int MOD = 1'000'000;
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
                dp[i+1][j][0] += dp[i][j][k] % MOD;
                if (!j) dp[i+1][j+1][0] += dp[i][j][k] % MOD;
                if (k <= 1) dp[i+1][j][k+1] += dp[i][j][k] % MOD;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            ans += dp[n][i][j] % MOD;
        }
    }
    ans %= MOD;
    cout << ans;
}