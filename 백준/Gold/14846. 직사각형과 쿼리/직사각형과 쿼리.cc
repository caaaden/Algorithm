#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int board[301][301];
int dp[301][301][11];
int main() {
    fastio;

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> board[i][j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int k = 1; k <= 10; ++k) dp[i][j][k] = dp[i-1][j][k] + dp[i][j-1][k] - dp[i-1][j-1][k];
            dp[i][j][board[i][j]]++;
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