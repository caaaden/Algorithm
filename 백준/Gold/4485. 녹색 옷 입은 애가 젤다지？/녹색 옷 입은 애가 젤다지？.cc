#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using pii = pair<int, int>;
using piii = pair<int, pii>;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int dijkstra(vector<vector<int>>& board, int n) {
    vector<vector<int>> dist(n, vector<int>(n, 1e9));
    priority_queue<piii, vector<piii>, greater<piii>> pq;
    dist[0][0] = board[0][0];
    pq.push({dist[0][0], {0, 0}});
    while (pq.size()) {
        int nowX = pq.top().second.first;
        int nowY = pq.top().second.second;
        int cost = pq.top().first;
        pq.pop();
//        if (dist[nowX][nowY] < cost) continue;
        for (int i = 0; i < 4; ++i) {
            // now / n, now % n
            int nextX = nowX + dx[i];
            int nextY = nowY + dy[i];
            if (nextX < 0 || nextX > n-1 || nextY < 0 || nextY > n-1) continue;
            int nextCost = cost + board[nextX][nextY];
            if (dist[nextX][nextY] <= nextCost) continue;
            dist[nextX][nextY] = nextCost;
            pq.push({nextCost, {nextX, nextY}});
        }
    }
    return dist[n-1][n-1];
}

int main() {
    fastio;

    int t = 1;
    while (true) {
        int n;
        cin >> n;
        if (!n) break;
        vector<vector<int>> board(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> board[i][j];
            }
        }
        cout << "Problem " << t << ": " << dijkstra(board, n) << '\n';
        t++;
    }
}