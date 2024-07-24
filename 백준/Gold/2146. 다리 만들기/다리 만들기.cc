#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using pii = pair<int, int>;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int main() {
    fastio;
    
    int n;
    cin >> n;
    vector<vector<int>> board(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> board[i][j];
        }
    }
    vector<vector<int>> regions(n + 1, vector<int>(n + 1));
    vector<vector<int>> vis(n + 1, vector<int>(n + 1));
    int regionNumber = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (!board[i][j]) continue;
            if (vis[i][j]) continue;
            vis[i][j] = 1;
            queue<pii> Q;
            Q.push({i, j});
            while (Q.size()) {
                int nowX = Q.front().first;
                int nowY = Q.front().second;
                Q.pop();
                regions[nowX][nowY] = regionNumber;
                for (int k = 0; k < 4; ++k) {
                    int nextX = nowX + dx[k];
                    int nextY = nowY + dy[k];
                    if (nextX < 1 || nextX > n || nextY < 1 || nextY > n) continue;
                    if (!board[nextX][nextY]) continue;
                    if (vis[nextX][nextY]) continue;
                    vis[nextX][nextY] = 1;
                    Q.push({nextX, nextY});
                }
            }
            regionNumber++;
        }
    }
    regionNumber = 1;
    vis.clear();
    vis.resize(n + 1, vector<int>(n + 1));
    int ans = INT_MAX;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (!board[i][j]) continue;
            if (vis[i][j]) continue;
            vis[i][j] = 1;
            vector<vector<int>> dist(n + 1, vector<int>(n + 1, -1));
            dist[i][j] = 0;
            queue<pii> Q;
            Q.push({i, j});
            queue<pii> Q2;
            while (Q.size()) {
                int nowX = Q.front().first;
                int nowY = Q.front().second;
                Q.pop();
                Q2.push({nowX, nowY});
                for (int k = 0; k < 4; ++k) {
                    int nextX = nowX + dx[k];
                    int nextY = nowY + dy[k];
                    if (nextX < 1 || nextX > n || nextY < 1 || nextY > n) continue;
                    if (!board[nextX][nextY]) continue;
                    if (vis[nextX][nextY]) continue;
                    vis[nextX][nextY] = 1;
                    dist[nextX][nextY] = 0;
                    Q.push({nextX, nextY});
                }
            }
            while (Q2.size()) {
                int nowX = Q2.front().first;
                int nowY = Q2.front().second;
                Q2.pop();
                if (dist[nowX][nowY] > 0 && regions[nowX][nowY] > 0) {
                    ans = min(ans, dist[nowX][nowY] - 1);
                    break;
                }
                for (int k = 0; k < 4; ++k) {
                    int nextX = nowX + dx[k];
                    int nextY = nowY + dy[k];
                    if (nextX < 1 || nextX > n || nextY < 1 || nextY > n) continue;
                    if (dist[nextX][nextY] != -1) continue;
                    dist[nextX][nextY] = dist[nowX][nowY] + 1;
                    Q2.push({nextX, nextY});
                }
            }
            regionNumber++;
        }
    }
    cout << ans;
}