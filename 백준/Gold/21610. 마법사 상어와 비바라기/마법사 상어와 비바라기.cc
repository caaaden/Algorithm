#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
using pii = pair<int, int>;

int dx[] = {INT_MAX, 0, -1, -1, -1, 0, 1, 1, 1};
int dy[] = {INT_MAX, -1, -1, 0, 1, 1, 1, 0, -1};
int main() {
    fastio;

    int n, m;
    cin >> n >> m;
    vector<vector<int>> board(n+1, vector<int>(n+1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> board[i][j];
        }
    }
    vector<pii> coords = {{n-1, 1}, {n-1, 2}, {n, 1}, {n, 2}};
    while (m--) {
        int d, s;
        cin >> d >> s;
        for (auto& [x, y] : coords) {
            x += dx[d] * s;
            y += dy[d] * s;
            while (x < 1) x += n;
            while (x > n) x -= n;
            while (y < 1) y += n;
            while (y > n) y -= n;
        }
        for (auto& [x, y] : coords) board[x][y]++;
        for (auto& [x, y] : coords) {
            int cnt = 0;
            for (int i = 2; i <= 8; i += 2) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 1 || nx > n || ny < 1 || ny > n) continue;
                if (!board[nx][ny]) continue;
                cnt++;
            }
            board[x][y] += cnt;
        }
        vector<pii> newCoords;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                bool flag = true;
                for (auto& [x, y] : coords) {
                    if (i == x && j == y) {
                        flag = false;
                        break;
                    }
                }
                if (!flag) continue;
                if (board[i][j] < 2) continue;
                board[i][j] -= 2;
                newCoords.push_back({i, j});
            }
        }
        coords = newCoords;
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            ans += board[i][j];
        }
    }
    cout << ans;
}
