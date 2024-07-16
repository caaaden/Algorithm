#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

struct Point {
    int x;
    int y;
    int z;
};

int dx[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};
int cube[4][5][5][5];
int main() {
    fastio;

    // rotate 한 상태를 이미 가지고 있을 것.
    // cube[0...4]
    // cube[a][b][c][d] : a번 돌린 b번째 판
    // array<array<int, 5>, 5> b1
    // rotate(array<array<int, 5>, 5>& board)
    // setOrder()

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            for (int k = 0; k < 5; ++k) {
                cin >> cube[0][i][j][k];
            }
        }
        // rotate
        for (int j = 0; j < 3; ++j) {
            for (int a = 0; a < 5; ++a) {
                for (int b = 0; b < 5; ++b) {
                    cube[j+1][i][b][4-a] = cube[j][i][a][b];
                }
            }
        }
    }
    vector<int> order = {0, 1, 2, 3, 4};
    int ans = INT_MAX;
    do {
        // idx = order[i]
        // cube[idx]
        for (int i = 0; i < (1 << 10); ++i) {
            // i의 0~1, 2~3, 4~5, 6~7, 8~9
            // i & 3
            // i >> 2
            int tmp = i; // i 자체를 수정하면 안되므로
            vector<int> rotates(5); // cube[rotates[0...4]][order[0...4]] : 윗판부터 아랫판까지 순서대로,
            for (int j = 0; j < 5; ++j, tmp >>= 2) rotates[j] = tmp & 3;
            for (int j = 0; j < (1 << 2); ++j) {
                Point s = {0, 0, 0};
                Point e = {0, 0, 4};
                if (j & 1) s.x = 4;
                else e.x = 4;
                if (j & 2) s.y = 4;
                else e.y = 4;
                // 시작칸 or 도착칸이 막혀있으면 continue
                if (!cube[rotates[s.x]][order[s.x]][s.y][s.z] || !cube[rotates[e.x]][order[e.x]][e.y][e.z]) continue;
                // s에서 bfs
                queue<Point> Q;
                Q.push(s);
                vector<vector<vector<int>>> dist(5, vector<vector<int>>(5, vector<int>(5, -1)));
                dist[s.x][s.y][s.z] = 0;
                while (Q.size()) {
                    Point now = Q.front();
                    Q.pop();
                    if (now.x == e.x && now.y == e.y && now.z == e.z) {
                        ans = min(ans, dist[e.x][e.y][e.z]);
                        if (ans == 12) {
                            cout << ans;
                            return 0;
                        }
                        break;
                    }
                    for (int k = 0; k < 6; ++k) {
                        Point next;
                        next.x = now.x + dx[k];
                        next.y = now.y + dy[k];
                        next.z = now.z + dz[k];
                        if (next.x < 0 || next.x > 4 || next.y < 0 || next.y > 4 || next.z < 0 || next.z > 4) continue;
                        if (!cube[rotates[next.x]][order[next.x]][next.y][next.z]) continue;
                        if (dist[next.x][next.y][next.z] != -1) continue;
                        dist[next.x][next.y][next.z] = dist[now.x][now.y][now.z] + 1;
                        Q.push(next);
                    }
                }
            }
        }
    } while (next_permutation(order.begin(), order.end()));
    cout << (ans == INT_MAX ? -1 : ans);
}