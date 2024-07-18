#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> board(n+1, vector<int>(m+1));
    for (int i = 0; i < k; ++i) {
        int x, y;
        cin >> x >> y;
        board[x][y] = 1;
    }
    int ans = 0;
    vector<vector<int>> vis(n+1, vector<int>(m+1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (!board[i][j]) continue;
            if (vis[i][j]) continue;
            int cnt = 0;
            queue<pii> Q;
            Q.push({i, j});
            vis[i][j] = 1;
            while (Q.size()) {
                int nowX = Q.front().first;
                int nowY = Q.front().second;
                Q.pop();
                cnt++;
                for (int i = 0; i < 4; ++i) {
                    int nextX = nowX + dx[i];
                    int nextY = nowY + dy[i];
                    if (nextX < 1 || nextX > n || nextY < 1 || nextY > m) continue;
                    if (!board[nextX][nextY]) continue;
                    if (vis[nextX][nextY]) continue;
                    Q.push({nextX, nextY});
                    vis[nextX][nextY] = 1;
                }
            }
            ans = max(ans, cnt);
        }
    }
    cout << ans;
}