#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> board(n+1, vector<int>(m+1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            char c;
            cin >> c;
            if ((i+j) % 2 == 0 && c == 'W') board[i][j] = 1;
            if ((i+j) % 2 == 1 && c == 'B') board[i][j] = 1;
        }
    }
    vector<vector<int>> dp(n+1, vector<int>(m+1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + board[i][j];
        }
    }
    int power = k*k;
    int ans = INT_MAX;
    for (int i = 1; i <= n-k+1; ++i) {
        for (int j = 1; j <= m-k+1; ++j) {
            int cnt = dp[i+k-1][j+k-1] - dp[i-1][j+k-1] - dp[i+k-1][j-1] + dp[i-1][j-1];
            ans = min(ans, min(cnt, power - cnt));
        }
    }
    cout << ans;
}