#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
using pii = pair<int, int>;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int main() {
    fastio;

    int r, c;
    cin >> r >> c;
    vector<vector<char>> board(r+1, vector<char>(c+1));
    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) {
            cin >> board[i][j];
        }
    }
    int n;
    cin >> n;
    // n = even -> from left
    // n = odd -> from right
    for (int i = 0; i < n; ++i) {
        int height;
        cin >> height;
        height = r - height + 1;
        if (i & 1) {
            for (int j = c; j >= 1; --j) {
                if (board[height][j] == '.') continue;
                board[height][j] = '.';
                break;
            }
        } else {
            for (int j = 1; j <= c; ++j) {
                if (board[height][j] == '.') continue;
                board[height][j] = '.';
                break;
            }
        }
        // bfs
//        for (int j = 1; j <= r; ++j) {
//            for (int k = 1; k <= c; ++k) {
//                cout << board[j][k];
//            }
//            cout << '\n';
//        }
//        cout << '\n';
        vector<vector<int>> vis(r+1, vector<int>(c+1));
        bool isMoved = false; // 이동 여부
        for (int j = 1; !isMoved && j <= r; ++j) {
            for (int k = 1; !isMoved && k <= c; ++k) {
                if (board[j][k] == '.') continue;
                if (vis[j][k]) continue;
                queue<pii> Q;
                Q.push({j, k});
                vis[j][k] = 1;
                vector<pii> cluster;
                cluster.push_back({j, k});
                vector<int> colMax(c+1);
                colMax[k] = j;
                while (Q.size()) {
                    int nowX = Q.front().first;
                    int nowY = Q.front().second;
                    Q.pop();
                    for (int dir = 0; dir < 4; ++dir) {
                        int nextX = nowX + dx[dir];
                        int nextY = nowY + dy[dir];
                        if (nextX < 1 || nextX > r || nextY < 1 || nextY > c) continue;
                        if (board[nextX][nextY] == '.') continue;
                        if (vis[nextX][nextY]) continue;
                        vis[nextX][nextY] = 1;
                        cluster.push_back({nextX, nextY});
                        colMax[nextY] = max(colMax[nextY], nextX);
                        Q.push({nextX, nextY});
                    }
                }
                // 각 열에서 가장 큰 x값
                // vector<int> colMax(c+1)
                // colMax[?] = 0 : 해당 열에는 클러스터가 존재하지 않음
                // colMax[?] = 1~r
                // colMax[?]

//                for (int ii = 1; ii <= c; ++ii) {
//                    cout << colMax[ii] << ' ';
//                }
//                cout << '\n';

                int minDist = INT_MAX;
                for (int ii = 1; ii <= c; ++ii) {
                    if (!colMax[ii]) continue;
                    // 모든 열에 대해서,
                    // colMax[ii] 아래에 가장 가까운 클러스터 or 바닥 구하기
                    int dist = 0; // 가장 가까운 다른 클러스터 or 바닥과의 거리
                    for (int jj = colMax[ii]+2; jj <= r; ++jj) {
                        if (board[jj][ii] == '.') continue;
                        dist = jj - colMax[ii] - 1;
                        break;
                    }
                    if (!dist) dist = r - colMax[ii];
                    minDist = min(minDist, dist);
                }
//                cout << minDist << '\n';
                // minDist만큼 현재 클러스터를 아래로 이동
                if (!minDist) continue; // 이동 x
                isMoved = true;
                // 모든 열에 대해, 맨 아래 행부터 이동
                // 열에 대해 오름차순 정렬, 행에 대해 내림차순 정렬
                sort(cluster.begin(), cluster.end(), [](const pii& a, const pii& b) {
                    if (a.second == b.second) {
                        return a.first > b.first;
                    } else {
                        return a.second < b.second;
                    }
                });
                for (auto& [a, b] : cluster) {
                    board[a][b] = '.';
                    board[a+minDist][b] = 'x';
                }
            }
        }
//        for (int i = 1; i <= r; ++i) {
//            for (int j = 1; j <= c; ++j) {
//                cout << board[i][j];
//            }
//            cout << '\n';
//        }
//        cout << '\n';
    }
    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) {
            cout << board[i][j];
        }
        cout << '\n';
    }
}