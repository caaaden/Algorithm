#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, l, r;
    cin >> n >> l >> r;
    vector<vector<int>> board(n+1, vector<int>(n+1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> board[i][j];
        }
    }
    int days = 0;
    bool flag = false;
    while (!flag) {
        flag = true;
        vector<vector<int>> vis(n+1, vector<int>(n+1));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (vis[i][j]) continue;
                int sum = 0;
                int cnt = 0;
                vector<pii> coords;
                queue<pii> Q;
                Q.push({i, j});
                vis[i][j] = 1;
                while (!Q.empty()) {
                    int nowX = Q.front().first;
                    int nowY = Q.front().second;
                    Q.pop();
                    sum += board[nowX][nowY];
                    cnt++;
                    coords.push_back({nowX, nowY});
                    for (int k = 0; k < 4; ++k) {
                        int nextX = nowX + dx[k];
                        int nextY = nowY + dy[k];
                        if (nextX < 1 || nextX > n || nextY < 1 || nextY > n) continue;
                        if (vis[nextX][nextY]) continue;
                        int diff = abs(board[nowX][nowY] - board[nextX][nextY]);
                        if (diff < l || diff > r) continue;
                        Q.push({nextX, nextY});
                        vis[nextX][nextY] = 1;
                    }
                }
                if (coords.size() == 1) continue;
                flag = false; // 연합이 최소 하나.
                int avg = sum / cnt;
                for (auto e : coords) board[e.first][e.second] = avg;
            }
        }
        if (!flag) days++;
    }
    cout << days;
}