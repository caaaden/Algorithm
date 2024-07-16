#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastio;

    int n, m;
    cin >> n >> m;
    vector<vector<int>> board(n+1, vector<int>(m+1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> board[i][j];
        }
    }
    vector<vector<int>> dp(n+1, vector<int>(m+1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            dp[i][j] = max({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + board[i][j];
        }
    }
    cout << dp[n][m];
}