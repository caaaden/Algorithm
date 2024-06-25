#include <bits/stdc++.h>

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
using pii = pair<int, int>;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int main() {
    fastio;

    int n, m;
    cin >> n >> m;
    vector<vector<int>> board(n+1, vector<int>(m+1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            char c;
            cin >> c;
            if (c == '1') board[i][j] = -1;
        }
    }
    vector<vector<int>> vis(n+1, vector<int>(m+1));
    vector<vector<int>> domain(n+1, vector<int>(m+1));
    int cnt = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (board[i][j]) continue;
            if (vis[i][j]) continue;
            queue<pii> Q;
            Q.push({i, j});
            vis[i][j] = 1;
            vector<pii> pos;
            while (Q.size()) {
                int nowX = Q.front().first;
                int nowY = Q.front().second;
                Q.pop();
                pos.push_back({nowX, nowY});
                for (int k = 0; k < 4; ++k) {
                    int nextX = nowX + dx[k];
                    int nextY = nowY + dy[k];
                    if (nextX < 1 || nextX > n || nextY < 1 || nextY > m) continue;
                    if (board[nextX][nextY]) continue;
                    if (vis[nextX][nextY]) continue;
                    vis[nextX][nextY] = 1;
                    Q.push({nextX, nextY});
                }
            }
            for (auto& [a, b] : pos) {
                board[a][b] = pos.size();
                domain[a][b] = cnt;
            }
            cnt++;
        }
    }
    vector<vector<int>> ans(n+1, vector<int>(m+1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (board[i][j] != -1) continue;
            ans[i][j]++;
            set<pii> st;
            for (int k = 0; k < 4; ++k) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
                if (board[nx][ny] == -1) continue;
                st.insert({domain[nx][ny], board[nx][ny]});
            }
            for (auto& [a, b] : st) {
                ans[i][j] += b;
            }
            ans[i][j] %= 10;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cout << ans[i][j];
        }
        cout << '\n';
    }
}