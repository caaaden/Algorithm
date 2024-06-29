#include <bits/stdc++.h>

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
using piii = pair<pair<int, int>, int>;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int main() {
    fastio;

    int n;
    cin >> n;
    vector<vector<int>> board(n+1, vector<int>(n+1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            char c;
            cin >> c;
            board[i][j] = c - '0';
            // 흰 방 : 1
            // 검은 방 : 0
        }
    }
    vector<vector<vector<int>>> vis(n+1, vector<vector<int>>(n+1, vector<int>(n*2-2))); // 0~2n-3
    vis[1][1][0] = 1;
    queue<piii> Q;
    Q.push({{1, 1}, 0});
    while (Q.size()) {
        int nowX = Q.front().first.first;
        int nowY = Q.front().first.second;
        int brokenWalls = Q.front().second;
        Q.pop();
        for (int i = 0; i < 4; ++i) {
            int nextX = nowX + dx[i];
            int nextY = nowY + dy[i];
            if (nextX < 1 || nextX > n || nextY < 1 || nextY > n) continue;
            if (board[nextX][nextY]) {
                // 흰 방
                if (vis[nextX][nextY][brokenWalls]) continue;
                vis[nextX][nextY][brokenWalls] = 1;
                Q.push({{nextX, nextY}, brokenWalls});
            } else {
                // 검은 방
                if (brokenWalls + 1 > n*2-3) continue;
                if (vis[nextX][nextY][brokenWalls+1]) continue;
                vis[nextX][nextY][brokenWalls+1] = 1;
                Q.push({{nextX, nextY}, brokenWalls+1});
            }
        }
    }
    for (int i = 0; i <= n*2-3; ++i) {
        if (!vis[n][n][i]) continue;
        cout << i;
        return 0;
    }
}