    #include <bits/stdc++.h>
    #define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    using namespace std;
    using pii = pair<int, int>;
    using piii = pair<int, pair<int, int>>;

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
            int edibleFish = 0; // 먹을 수 있는 물고기까지의 거리
            bool flag = true;
            vector<pii> v; // 먹을 수 있는 물고기들의 좌표
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
                        // 먹을 수 있는 물고기를 발견
                        // 해당 dist까지만 bfs를 돌린 뒤 그 중 우선순위 물고기 먹기
                        if (!edibleFish) {
                            // 최초 발견 시
                            edibleFish = dist[nextX][nextY];
                        }
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
    // 현재 아기 상어의 위치에서 bfs를 돌린다.
    // Q에 좌표 + 거리를 삽입한다.
    // 탐색 중 조건에 맞는 물고기(상어의 크기보다 작은)를 발견할 경우 해당 거리까지만 탐색한다.
    // 즉 조건에 맞는 물고기를 발견함과 동시에 벡터에 좌표를 삽입해주고 정렬한다.