#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
using i64 = long long;

const i64 MOD = 1e9 + 7;
int main() {
    fastio;

    int n;
    cin >> n;
    vector<i64> dp(n+1);
    dp[0] = 1;
    dp[1] = 2;
    i64 sum = dp[0] + dp[1];
    for (int i = 2; i <= n; ++i) {
        dp[i] = (sum * 2 + dp[i-2]) % MOD;
        sum = (sum + dp[i]) % MOD;
    }
    cout << dp[n];
}