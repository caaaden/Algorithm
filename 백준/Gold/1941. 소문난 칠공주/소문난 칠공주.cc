#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
using pii = pair<int, int>;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
vector<vector<char>> board(5, vector<char>(5));
vector<vector<int>> board2(5, vector<int>(5));
int cntY;
int ans;
void dfs(int k, int idx) {
    if (k == 7) {
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                if (!board2[i][j]) continue;
                queue<pii> Q;
                Q.push({i, j});
                vector<vector<int>> vis(5, vector<int>(5));
                vis[i][j] = 1;
                int cnt = 0;
                while (Q.size()) {
                    int nowX = Q.front().first;
                    int nowY = Q.front().second;
                    Q.pop();
                    cnt++;
                    for (int dir = 0; dir < 4; ++dir) {
                        int nextX = nowX + dx[dir];
                        int nextY = nowY + dy[dir];
                        if (nextX < 0 || nextX > 4 || nextY < 0 || nextY > 4) continue;
                        if (!board2[nextX][nextY]) continue;
                        if (vis[nextX][nextY]) continue;
                        vis[nextX][nextY] = 1;
                        Q.push({nextX, nextY});
                    }
                }
                ans += cnt == 7;
                return;
            }
        }
    }
    for (int i = idx; i < 25; ++i) {
        int x = i / 5;
        int y = i % 5;
        if (board[x][y] == 'Y') cntY++;
        if (cntY > 3) {
            cntY--;
            continue;
        }
        board2[x][y] = 1;
        dfs(k+1, i+1);
        board2[x][y] = 0;
        if (board[x][y] == 'Y') cntY--;
    }
}

int main() {
    fastio;

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cin >> board[i][j];
        }
    }
    dfs(0, 0);
    cout << ans;
}
