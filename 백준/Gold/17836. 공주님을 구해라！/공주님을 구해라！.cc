#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using pii = pair<int, int>;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
const int MAX = 1e9;
int main() {
    fastio;

    int n, m, t;
    cin >> n >> m >> t;
    vector<vector<int>> board(n+1, vector<int>(m+1));
    int gramrX, gramrY;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> board[i][j];
            if (board[i][j] == 2) {
                gramrX = i;
                gramrY = j;
            }
        }
    }
    int ans = INT_MAX;
    auto bfs = [&n, &m, &board](int x, int y) {
        queue<pii> Q;
        Q.push({1, 1});
        vector<vector<int>> dist(n+1, vector<int>(m+1, -1));
        dist[1][1] = 0;
        while (Q.size()) {
            int nowX = Q.front().first;
            int nowY = Q.front().second;
            Q.pop();
            if (nowX == x && nowY == y) return dist[x][y];
            for (int i = 0; i < 4; ++i) {
                int nextX = nowX + dx[i];
                int nextY = nowY + dy[i];
                if (nextX < 1 || nextX > n || nextY < 1 || nextY > m) continue;
                if (board[nextX][nextY] == 1) continue;
                if (dist[nextX][nextY] != -1) continue;
                dist[nextX][nextY] = dist[nowX][nowY] + 1;
                Q.push({nextX, nextY});
            }
        }
        return MAX;
    };
    ans = min(ans, bfs(gramrX, gramrY) + abs(gramrX-n) + abs(gramrY-m));
    ans = min(ans, bfs(n, m));
    if (ans > t) cout << "Fail";
    else cout << ans;
}