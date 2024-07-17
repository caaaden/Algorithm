#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using pii = pair<int, int>;
using piii = pair<pii, int>;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int main() {
    fastio;

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> board(n+1, vector<int>(m+1));
    vector<vector<int>> vis(n+1, vector<int>(m+1)); // for 마네킹
    vector<vector<int>> dist(n+1, vector<int>(m+1, -1));
    queue<piii> Q; // {{x, y}, dist}
    queue<pii> Q2;
    // 0 : 빈 칸
    // 1 : 벽
    // 2 : 도착점
    // 3 : 마네킹
    // 4 : 시작점
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> board[i][j];
            if (board[i][j] == 3) {
                Q.push({{i, j}, 0});
                vis[i][j] = 1;
            }
            if (board[i][j] == 4) {
                Q2.push({i, j});
                dist[i][j] = 0;
            }
        }
    }
    // 벽, 시작점 무시
    while (Q.size()) {
        int nowX = Q.front().first.first;
        int nowY = Q.front().first.second;
        int nowDist = Q.front().second;
        Q.pop();
        if (nowDist == k) continue;
        for (int i = 0; i < 4; ++i) {
            int nextX = nowX + dx[i];
            int nextY = nowY + dy[i];
            if (nextX < 1 || nextX > n || nextY < 1 || nextY > m) continue;
            if (vis[nextX][nextY]) continue;
            vis[nextX][nextY] = 1;
            Q.push({{nextX, nextY}, nowDist+1});
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            // 마네킹이 영향을 미치는 범위, 즉 방문한 정점을 모두 '기둥'화 시키기
            // 시작점 제외
            // 도착점 포함
            // 기둥이면? 덮어씌우나 안 씌우나 똑같음
            // vis[i][j]
            if (!vis[i][j]) continue;
            if (board[i][j] == 1 || board[i][j] == 4) continue;
            board[i][j] = 1;
        }
    }
    while (Q2.size()) {
        // board = 4이면 정지하고 거리 출력
        int nowX = Q2.front().first;
        int nowY = Q2.front().second;
        Q2.pop();
        if (board[nowX][nowY] == 2) {
            cout << dist[nowX][nowY];
            return 0;
        }
        for (int i = 0; i < 4; ++i) {
            int nextX = nowX + dx[i];
            int nextY = nowY + dy[i];
            if (nextX < 1 || nextX > n || nextY < 1 || nextY > m) continue;
            if (board[nextX][nextY] == 1) continue;
            if (dist[nextX][nextY] != -1) continue;
            dist[nextX][nextY] = dist[nowX][nowY] + 1;
            Q2.push({nextX, nextY});
        }
    }
    cout << -1;
}