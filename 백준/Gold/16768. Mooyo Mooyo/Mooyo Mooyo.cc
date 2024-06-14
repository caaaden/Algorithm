#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using pii = pair<int, int>;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<vector<int>> board(n+1, vector<int>(11));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= 10; ++j) {
            char c;
            cin >> c;
            board[i][j] = c - '0';
        }
    }
    while (true) {
        // needToErase.empty() -> break
        vector<vector<int>> vis(n+1, vector<int>(11));
        vector<pii> needToErase;
        needToErase.reserve(n*10);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= 10; ++j) {
                if (!board[i][j]) continue;
                if (vis[i][j]) continue;
                // i, j를 시작으로 bfs
                // k개 이상일 경우 cands에 있는 점들을 needToErase로 옮기기
                vector<pii> cands; // 방문한 점들을 임시로 여기에 저장 후 k개 이상일 경우 needToErase로 옮기기
                cands.reserve(n*10);
                int cnt = 1; // 덩어리의 크기
                queue<pii> Q;
                Q.push({i, j});
                vis[i][j] = 1;
                cands.push_back({i, j});
                while (Q.size()) {
                    int nowX = Q.front().first;
                    int nowY = Q.front().second;
                    Q.pop();
                    for (int dir = 0; dir < 4; ++dir) {
                        int nextX = nowX + dx[dir];
                        int nextY = nowY + dy[dir];
                        if (nextX < 1 || nextX > n || nextY < 1 || nextY > 10) continue;
                        if (board[nextX][nextY] != board[nowX][nowY]) continue;
                        if (vis[nextX][nextY]) continue;
                        vis[nextX][nextY] = 1;
                        cands.push_back({nextX, nextY});
                        Q.push({nextX, nextY});
                        cnt++;
                    }
                }
                if (cnt < k) continue;
                for (auto& e : cands) needToErase.push_back(e);
            }
        }
        if (needToErase.empty()) break;
        for (auto& [x, y] : needToErase) board[x][y] = 0;
        for (int i = 1; i <= 10; ++i) {
            vector<int> tmp;
            tmp.reserve(n);
            for (int j = n; j >= 1; --j) {
                if (!board[j][i]) continue;
                tmp.push_back(board[j][i]);
                board[j][i] = 0;
            }
            for (int j = 0; j < tmp.size(); ++j) {
                board[n-j][i] = tmp[j];
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= 10; ++j) {
            cout << board[i][j];
        }
        cout << '\n';
    }
}