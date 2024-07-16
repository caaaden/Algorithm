#include <bits/stdc++.h>
using namespace std;
int board[1001][1001];
int cache[1001][1001];
int n, m;
int dp(int x, int y) {
    // x, y 는 좌표.
    // 경로의 최댓값을 리턴한다.
    int mmax = 0;
    if (x+1 <= n) {
        if (cache[x+1][y] == -1) {
            cache[x+1][y] = dp(x+1, y);
        }
        mmax = max(mmax, cache[x+1][y]);
    }
    if (y+1 <= m) {
        if (cache[x][y+1] == -1) {
            cache[x][y+1] = dp(x, y+1);
        }
        mmax = max(mmax, cache[x][y+1]);
    }
    if (x+1 <= n && y+1 <= m) {
        if (cache[x+1][y+1] == -1) {
            cache[x+1][y+1] = dp(x+1, y+1);
        }
        mmax = max(mmax, cache[x+1][y+1]);
    }
    
    return board[x][y] + mmax;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cache[i][j] = -1;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> board[i][j];
        }
    }
    cout << dp(1, 1);
}