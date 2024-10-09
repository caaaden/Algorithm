#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main() {
    fastio;

    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(2, vector<int>(m+1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i-1] == b[j-1]) dp[1][j] = dp[0][j-1] + 1;
            else dp[1][j] = max(dp[0][j], dp[1][j-1]);
        }
        swap(dp[0], dp[1]);
    }
    cout << dp[0][m];
}