#include <bits/stdc++.h>
using namespace std;
using piii = pair<pair<int, int>, int>;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // n+m-3 : 뚫고 가는 벽의 최대 개수. 이를 넘을 경우 continue
    // 100*100*200
    int n, m;
    cin >> m >> n;
    vector<vector<int>> board(n+1, vector<int>(m+1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            char c;
            cin >> c;
            board[i][j] = c-'0';
        }
    }
    if (n == 1 && m == 1) {
        cout << 0;
        return 0;
    }
    vector<vector<vector<int>>> vis(n+1, vector<vector<int>>(m+1, vector<int>(n+m-2)));
    // 1, 1 ~ n, m
    queue<piii> Q;
    Q.push({{1, 1}, 0});
    vis[1][1][0] = 1; // 1, 1을 벽을 0개 부신 상태에서 방문
    while (Q.size()) {
        int nowX = Q.front().first.first;
        int nowY = Q.front().first.second;
        int brokenWalls = Q.front().second;
        Q.pop();
        for (int i = 0; i < 4; ++i) {
            int nextX = nowX + dx[i];
            int nextY = nowY + dy[i];
            if (nextX < 1 || nextX > n || nextY < 1 || nextY > m) continue;
            if (board[nextX][nextY]) {
                // 이동할 곳이 벽일 때,
                // 벽을 부수고 이동하는 경우
                // nowX, nowY, brokenWalls
                // nextX, nextY, broeknWalls+1
                // vis[nextX][nextY][brokenWalls+1]
                // n+m-3 == brokenWalls : 더 이상 벽을 부술 수 없으므로 이동 불가
                if (brokenWalls == n+m-3) continue;
                if (vis[nextX][nextY][brokenWalls+1]) continue;
                Q.push({{nextX, nextY}, brokenWalls+1});
                vis[nextX][nextY][brokenWalls+1] = 1;
            } else {
                // 이동할 곳이 빈 방일 경우
                if (vis[nextX][nextY][brokenWalls]) continue;
                Q.push({{nextX, nextY}, brokenWalls});
                vis[nextX][nextY][brokenWalls] = 1;
            }
        }
    }
    // vis[n][m][0...n+m-3]
    for (int i = 0; i < n+m-2; ++i) {
        if (vis[n][m][i]) {
            cout << i;
            return 0;
        }
    }
}