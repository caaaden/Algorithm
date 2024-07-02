#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
using pii = pair<int, int>;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
bool bfs(array<array<char, 5>, 5>& board, vector<vector<int>>& board2) {
    int cnt = 0;
    int cntY = 0;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (!board2[i][j]) continue;
            vector<vector<int>> vis(5, vector<int>(5));
            vis[i][j] = 1;
            queue<pii> Q;
            Q.push({i, j});
            while (Q.size()) {
                int nowX = Q.front().first;
                int nowY = Q.front().second;
                Q.pop();
                cnt++;
                if (board[nowX][nowY] == 'Y') cntY++;
                for (int k = 0; k < 4; ++k) {
                    int nextX = nowX + dx[k];
                    int nextY = nowY + dy[k];
                    if (nextX < 0 || nextX > 4 || nextY < 0 || nextY > 4) continue;
                    if (!board2[nextX][nextY]) continue;
                    if (vis[nextX][nextY]) continue;
                    vis[nextX][nextY] = 1;
                    Q.push({nextX, nextY});
                }
            }
            if (cnt != 7) return false;
            if (cntY > 3) return false;
            return true;
        }
    }
    return true; //
}

int main() {
    fastio;

    array<array<char, 5>, 5> board;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cin >> board[i][j];
        }
    }
    int ans = 0;
    for (int a = 0; a < 25; ++a) {
        for (int b = a+1; b < 25; ++b) {
            for (int c = b+1; c < 25; ++c) {
                for (int d = c+1; d < 25; ++d) {
                    for (int e = d+1; e < 25; ++e) {
                        for (int f = e+1; f < 25; ++f) {
                            for (int g = f+1; g < 25; ++g) {
                                vector<vector<int>> board2(5, vector<int>(5));
                                board2[a/5][a%5] = 1;
                                board2[b/5][b%5] = 1;
                                board2[c/5][c%5] = 1;
                                board2[d/5][d%5] = 1;
                                board2[e/5][e%5] = 1;
                                board2[f/5][f%5] = 1;
                                board2[g/5][g%5] = 1;
                                ans += bfs(board, board2);
                            }
                        }
                    }
                }
            }
        }
    }
    cout << ans;
}
