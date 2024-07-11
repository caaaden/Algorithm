#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main() {
    fastio;

    int n;
    cin >> n;
    vector<vector<int>> board(n+1, vector<int>(n+1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> board[i][j];
        }
    }
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(n+1, vector<int>(11))); // dp[a][b][c] = (1, 1)~(a, b)에 포함된 정수 c(1~10)의 개수
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int k = 1; k <= 10; ++k) {
                dp[i][j][k] = dp[i-1][j][k] + dp[i][j-1][k] - dp[i-1][j-1][k];
                if (board[i][j] == k) dp[i][j][k]++;
            }
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int cnt = 0;
        for (int i = 1; i <= 10; ++i) if (dp[x2][y2][i] - dp[x1-1][y2][i] - dp[x2][y1-1][i] + dp[x1-1][y1-1][i] > 0) cnt++;
        cout << cnt << '\n';
    }
}