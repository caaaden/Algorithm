#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using pii = pair<int, int>;

struct Point {
    int x, y, mirror, dir;
};

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int main() {
    fastio;

    int n, m;
    cin >> m >> n;
    vector<vector<char>> board(n+1, vector<char>(m+1));
    vector<pii> twoNodes;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> board[i][j];
            if (board[i][j] == 'C') {
                twoNodes.push_back({i, j});
            }
        }
    }
    // origin : twoNodes[0]
    // destination : twoNodes[1]
    // vis[a][b][c] : {a, b}의 c방향으로 도착했을 때 설치한 거울의 개수의 최솟값
    vector<vector<vector<int>>> vis(n+1, vector<vector<int>>(m+1, vector<int>(4, INT_MAX)));
    // {{x, y}, {설치한 거울의 개수, 방향}}
    queue<Point> Q;
    for (int i = 0; i < 4; ++i) {
        int nextX = twoNodes[0].first + dx[i];
        int nextY = twoNodes[0].second + dy[i];
        if (nextX < 1 || nextX > n || nextY < 1 || nextY > m) continue;
        if (board[nextX][nextY] == '*') continue;
        Q.push({nextX, nextY, 0, i});
        vis[twoNodes[0].first][twoNodes[0].second][i] = 0;
        vis[nextX][nextY][i] = 0;
    }
    while (Q.size()) {
        int nowX = Q.front().x;
        int nowY = Q.front().y;
        int mirror = Q.front().mirror;
        int dir = Q.front().dir;
        Q.pop();
        for (int i = 0; i < 4; ++i) {
            int nextX = nowX + dx[i];
            int nextY = nowY + dy[i];
            if (nextX < 1 || nextX > n || nextY < 1 || nextY > m) continue;
            if (board[nextX][nextY] == '*') continue;
            if (i == dir) {
                if (vis[nextX][nextY][i] > mirror) {
                    vis[nextX][nextY][i] = mirror;
                    Q.push({nextX, nextY, mirror, i});
                }
            } else {
                if (vis[nextX][nextY][i] > mirror+1) {
                    vis[nextX][nextY][i] = mirror+1;
                    Q.push({nextX, nextY, mirror+1, i});
                }
            }
        }
    }
    int ans = INT_MAX;
    for (int i = 0; i < 4; ++i) {
        ans = min(ans, vis[twoNodes[1].first][twoNodes[1].second][i]);
    }
    cout << ans;

}