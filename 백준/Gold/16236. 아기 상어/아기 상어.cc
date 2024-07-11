#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
using pii = pair<int, int>;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int main() {
    fastio;

    int n;
    cin >> n;
    vector<vector<int>> board(n+1, vector<int>(n+1));
    int sx, sy;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> board[i][j];
            if (board[i][j] == 9) {
                sx = i;
                sy = j;
            }
        }
    }
    int totalTime = 0;
    int sizeOfBabyShark = 2;
    int eatenFish = 0;
    while (true) {
        vector<vector<int>> dist(n+1, vector<int>(n+1, -1));
        queue<pii> Q;
        Q.push({sx, sy});
        dist[sx][sy] = 0;
        int edibleFish = 0;
        bool flag = true;
        vector<pii> v;
        while (Q.size()) {
            int nowX = Q.front().first;
            int nowY = Q.front().second;
            Q.pop();
            for (int i = 0; i < 4; ++i) {
                int nextX = nowX + dx[i];
                int nextY = nowY + dy[i];
                if (nextX < 1 || nextX > n || nextY < 1 || nextY > n) continue;
                if (dist[nextX][nextY] != -1) continue;
                if (board[nextX][nextY] > sizeOfBabyShark) continue;
                dist[nextX][nextY] = dist[nowX][nowY] + 1;
                Q.push({nextX, nextY});
                if (board[nextX][nextY] != 0 && board[nextX][nextY] < sizeOfBabyShark) {
                    if (!edibleFish) edibleFish = dist[nextX][nextY];
                    if (edibleFish == dist[nextX][nextY]) {
                        v.push_back({nextX, nextY});
                    } else {
                        flag = false;
                        break;
                    }
                }
            }
            if (!flag) break;
        }
        if (v.empty()) {
            cout << totalTime;
            return 0;
        }
        sort(v.begin(), v.end());
        totalTime += edibleFish;
        eatenFish++;
        if (eatenFish == sizeOfBabyShark) {
            eatenFish = 0;
            sizeOfBabyShark++;
        }
        board[sx][sy] = 0;
        board[v[0].first][v[0].second] = 9;
        sx = v[0].first;
        sy = v[0].second;
    }
}