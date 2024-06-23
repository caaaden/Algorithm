#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int r, c;
vector<vector<char>> board;
vector<vector<int>> dist;
vector<pii> swans;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool check(int mid) {
    // 빙하가 mid까지 녹았다고 가정할 때 bfs
    // dist[x] <= mid이면 통과
    queue<pii> Q;
    vector<vector<int>> vis(r+1, vector<int>(c+1));
    Q.push(swans[0]);
    vis[swans[0].first][swans[0].second] = 1;
    while (Q.size()) {
        int nowX = Q.front().first;
        int nowY = Q.front().second;
        Q.pop();
        if (nowX == swans[1].first && nowY == swans[1].second) return true;
        for (int i = 0; i < 4; ++i) {
            int nextX = nowX + dx[i];
            int nextY = nowY + dy[i];
            if (nextX < 1 || nextX > r || nextY < 1 || nextY > c) continue;
            if (dist[nextX][nextY] > mid) continue;
            if (vis[nextX][nextY]) continue;
            vis[nextX][nextY] = 1;
            Q.push({nextX, nextY});
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c;
    board.resize(r+1, vector<char>(c+1));
    dist.resize(r+1, vector<int>(c+1, -1));
    swans.reserve(2);
    queue<pii> Q;
    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) {
            cin >> board[i][j];
            // . X L
            if (board[i][j] == 'X') continue;
            if (board[i][j] == 'L') swans.push_back({i, j});
            dist[i][j] = 0;
            Q.push({i, j});
        }
    }
    int lo = -1, hi = 0;
    while (Q.size()) {
        int nowX = Q.front().first;
        int nowY = Q.front().second;
        hi = max(hi, dist[nowX][nowY]);
        Q.pop();
        for (int i = 0; i < 4; ++i) {
            int nextX = nowX + dx[i];
            int nextY = nowY + dy[i];
            if (nextX < 1 || nextX > r || nextY < 1 || nextY > c) continue;
            if (dist[nextX][nextY] != -1) continue;
            dist[nextX][nextY] = dist[nowX][nowY] + 1;
            Q.push({nextX, nextY});
        }
    }
    // FF...FFTT...TT
    // lo = -1, hi = dist의 최댓값
    while (lo+1 < hi) {
        int mid = (lo+hi) / 2;
        if (check(mid)) hi = mid;
        else lo = mid;
    }
    cout << hi;
}