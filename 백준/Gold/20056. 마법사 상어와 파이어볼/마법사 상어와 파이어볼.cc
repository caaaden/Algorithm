#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
using pii = pair<int, int>;
using piii = pair<int, pair<int, int>>;

int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
int main() {
    fastio;

    int n, m, k;
    cin >> n >> m >> k; 
    vector<vector<vector<piii>>> board(n+1, vector<vector<piii>>(n+1));
    for (int i = 0; i < m; ++i) {
        int r, c, mass, s, d;
        cin >> r >> c >> mass >> s >> d;
        board[r][c].push_back({mass, {s, d}});
    }
    while (k--) {
        vector<vector<vector<piii>>> newBoard(n+1, vector<vector<piii>>(n+1));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                for (auto& fireBall : board[i][j]) {
                    int mass = fireBall.first;
                    int speed = fireBall.second.first;
                    int dir = fireBall.second.second;
                    int nx = i + dx[dir] * speed;
                    int ny = j + dy[dir] * speed;
                    while (nx < 1) nx += n;
                    while (nx > n) nx -= n;
                    while (ny < 1) ny += n;
                    while (ny > n) ny -= n;
                    newBoard[nx][ny].push_back({mass, {speed, dir}});
                }
            }
        }
        board.clear();
        board.resize(n+1, vector<vector<piii>>(n+1));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (newBoard[i][j].empty()) continue;
                if (newBoard[i][j].size() == 1) {
                    board[i][j].push_back(newBoard[i][j][0]);
                    continue;
                }
                int totalMass = 0;
                int totalSpeed = 0;
                bool odd = false, even = false;
                for (auto& fireBall : newBoard[i][j]) {
                    totalMass += fireBall.first;
                    totalSpeed += fireBall.second.first;
                    if (fireBall.second.second & 1) odd = true;
                    else even = true;
                }
                totalMass /= 5;
                if (!totalMass) continue;
                totalSpeed /= newBoard[i][j].size();
                if (odd && even) {
                    for (auto& dir : {1, 3, 5, 7}) {
                        board[i][j].push_back({totalMass, {totalSpeed, dir}});
                    }
                } else {
                    for (auto& dir : {0, 2, 4, 6}) {
                        board[i][j].push_back({totalMass, {totalSpeed, dir}});
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (auto& fireBall : board[i][j]) {
                ans += fireBall.first;
            }
        }
    }
    cout << ans;
}