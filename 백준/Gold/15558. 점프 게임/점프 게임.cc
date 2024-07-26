#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using pii = pair<int, int>;

int main() {
    fastio;

    int n, k;
    cin >> n >> k;
    vector<vector<int>> board(3, vector<int>(n+1));
    for (int i = 1; i <= 2; ++i) {
        for (int j = 1; j <= n; ++j) {
            char c;
            cin >> c;
            board[i][j] = c - '0';
        }
    }
    vector<vector<int>> dist(3, vector<int>(n+1, -1));
    dist[1][1] = 0;
    queue<pii> Q;
    Q.push({1, 1});
    while (Q.size()) {
        int nowX = Q.front().first;
        int nowY = Q.front().second;
        Q.pop();
        vector<pii> nexts = {{nowX, nowY+1}, {nowX, nowY-1}, {3-nowX, nowY+k}};
        for (auto& [nextX, nextY] : nexts) {
            if (nextY <= dist[nowX][nowY]+1) continue;
            if (nextY > n) {
                cout << 1;
                return 0;
            }
            if (!board[nextX][nextY]) continue;
            if (dist[nextX][nextY] != -1) continue;
            dist[nextX][nextY] = dist[nowX][nowY] + 1;
            Q.push({nextX, nextY});
        }
    }
    cout << 0;
}