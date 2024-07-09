#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
using pii = pair<int, int>;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int main() {
    fastio;

    int r, c;
    cin >> r >> c;
    vector<vector<char>> board(r+1, vector<char>(c+1));
    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) {
            cin >> board[i][j];
        }
    }
    int minX = INT_MAX, minY = INT_MAX, maxX = INT_MIN, maxY = INT_MIN;
    vector<vector<char>> res(r+1, vector<char>(c+1, '.'));
    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) {
            if (board[i][j] == '.') continue;
            int cnt = 0;
            for (int k = 0; k < 4; ++k) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (nx < 1 || nx > r || ny < 1 || ny > c) {
                    cnt++;
                    continue;
                }
                if (board[nx][ny] == 'X') continue;
                cnt++;
            }
            if (cnt >= 3) continue;
            res[i][j] = 'X';
            minX = min(minX, i);
            minY = min(minY, j);
            maxX = max(maxX, i);
            maxY = max(maxY, j);
        }
    }
    for (int i = minX; i <= maxX; ++i) {
        for (int j = minY; j <= maxY; ++j) {
            cout << res[i][j];
        }
        cout << '\n';
    }
}
