#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
using pii = pair<int, int>;

int main() {
    fastio;

    int n, m;
    cin >> n >> m;
    vector<vector<int>> board(n+1, vector<int>(m+1));
    vector<vector<int>> dist(n+1, vector<int>(m+1, -1));
    queue<pii> Q;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> board[i][j];
            if (board[i][j] == 2) {
                dist[i][j] = 0;
                Q.push({i, j});
            }
        }
    }
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    while (Q.size()) {
        int nowX = Q.front().first;
        int nowY = Q.front().second;
        Q.pop();
        for (int i = 0; i < 4; ++i) {
            int nextX = nowX + dx[i];
            int nextY = nowY + dy[i];
            if (nextX < 1 || nextX > n || nextY < 1 || nextY > m) continue;
            if (!board[nextX][nextY]) continue;
            if (dist[nextX][nextY] != -1) continue;
            dist[nextX][nextY] = dist[nowX][nowY] + 1;
            Q.push({nextX, nextY});
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (!board[i][j]) cout << 0 << ' ';
            else cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }
}