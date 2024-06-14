#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

vector<vector<int>> board(13, vector<int>(7));
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int explode() {
    vector<vector<int>> vis(13, vector<int>(7));
    bool isExploded = false;
    for (int i = 1; i <= 12; ++i) {
        for (int j = 1; j <= 6; ++j) {
            if (!board[i][j]) continue;
            if (vis[i][j]) continue;
            int color = board[i][j];
            vis[i][j] = 1;
            queue<pii> Q;
            Q.push({i, j});
            vector<pii> visPoints;
            while (Q.size()) {
                int nowX = Q.front().first;
                int nowY = Q.front().second;
                Q.pop();
                visPoints.push_back({nowX, nowY});
                for (int k = 0; k < 4; ++k) {
                    int nextX = nowX + dx[k];
                    int nextY = nowY + dy[k];
                    if (nextX < 1 || nextX > 12 || nextY < 1 || nextY > 6) continue;
                    if (!board[nextX][nextY]) continue;
                    if (board[nextX][nextY] != color) continue;
                    if (vis[nextX][nextY]) continue;
                    vis[nextX][nextY] = 1;
                    Q.push({nextX, nextY});
                }
            }
            if (visPoints.size() < 4) continue;
            if (!isExploded) isExploded = true;
            for (auto &[a, b]: visPoints) board[a][b] = 0;
        }
    }
    return isExploded;
}

void fallDown() {
    for (int i = 1; i <= 6; ++i) {
        vector<int> nums;
        for (int j = 12; j >= 1; --j) {
            if (!board[j][i]) continue;
            nums.push_back(board[j][i]);
        }
        for (int j = 12, k = 0; j >= 1; --j, ++k) {
            if (k < nums.size()) board[j][i] = nums[k];
            else board[j][i] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //  11559
    for (int i = 1; i <= 12; ++i) {
        for (int j = 1; j <= 6; ++j) {
            char c;
            cin >> c;
            if (c == '.') board[i][j] = 0;
            else if (c == 'R') board[i][j] = 1;
            else if (c == 'G') board[i][j] = 2;
            else if (c == 'B') board[i][j] = 3;
            else if (c == 'P') board[i][j] = 4;
            else board[i][j] = 5;
        }
    }
    int ans = 0;
    while (true) {
        if (!explode()) break;
        ans++;
        fallDown();
    }
    cout << ans;
}