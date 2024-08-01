#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using pii = pair<int, int>;
using pic = pair<int, char>;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int main() {
    fastio;

    int n, m, p;
    cin >> n >> m >> p;
    vector<vector<char>> board(n+1, vector<char>(m+1));
    queue<pii> Q;
    vector<vector<int>> dist(n+1, vector<int>(m+1, -1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> board[i][j];
            if (board[i][j] == 'B') {
                Q.push({i, j});
                dist[i][j] = 0;
            }
        }
    }
    unordered_map<char, int> dps;
    for (int i = 0; i < p; ++i) {
        char player;
        int damage;
        cin >> player >> damage;
        dps.insert({player, damage});
    }
    int bossHp;
    cin >> bossHp;
    // BFS from boss
    // player, dist
    vector<pic> shortestDist;
    while (Q.size()) {
        int nowX = Q.front().first;
        int nowY = Q.front().second;
        Q.pop();
        if (board[nowX][nowY] >= 'a' && board[nowX][nowY] <= 'z') {
            shortestDist.push_back({dist[nowX][nowY], board[nowX][nowY]});
        }
        for (int i = 0; i < 4; ++i) {
            int nextX = nowX + dx[i];
            int nextY = nowY + dy[i];
            if (nextX < 1 || nextX > n || nextY < 1 || nextY > m) continue;
            if (board[nextX][nextY] == 'X') continue;
            if (dist[nextX][nextY] != -1) continue;
            dist[nextX][nextY] = dist[nowX][nowY] + 1;
            Q.push({nextX, nextY});
        }
    }
    // 최단거리 오름차순으로 정렬
    sort(shortestDist.begin(), shortestDist.end());
    int cumulativeDPS = 0;
    int sum = 0;
    for (int i = 1; i < p; ++i) {
        int diff = shortestDist[i].first - shortestDist[i-1].first;
        cumulativeDPS += dps[shortestDist[i-1].second];
        sum += cumulativeDPS * diff;
        if (sum >= bossHp) {
            cout << i;
            return 0;
        }
    }
    cout << p;
}