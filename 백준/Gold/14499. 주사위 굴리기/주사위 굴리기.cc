#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main() {
    fastio;

    int n, m, x, y, k;
    cin >> n >> m >> x >> y >> k;
    vector<vector<int>> board(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }
    // 현재 주사위에 쓰여 있는 수
    // T B E W S N
    int top = 0, bottom = 0;
    int east = 0, west = 0, south = 0, north = 0;
    auto copy = [&]() {
        if (board[x][y]) {
            bottom = board[x][y];
            board[x][y] = 0;
        } else {
            board[x][y] = bottom;
        }
    };
    while (k--) {
        int command;
        cin >> command;
        // E : 1, W : 2, N : 3, S : 4
        if (command == 1) {
            // 동쪽으로 이동
            if (y == m-1) continue;
            int tmp = top;
            top = west;
            west = bottom;
            bottom = east;
            east = tmp;
            y++;
        } else if (command == 2) {
            // 서쪽
            if (y == 0) continue;
            int tmp = top;
            top = east;
            east = bottom;
            bottom = west;
            west = tmp;
            y--;
        } else if (command == 3) {
            // 북쪽
            if (x == 0) continue;
            int tmp = top;
            top = south;
            south = bottom;
            bottom = north;
            north = tmp;
            x--;
        } else {
            // 남쪽
            if (x == n-1) continue;
            int tmp = top;
            top = north;
            north = bottom;
            bottom = south;
            south = tmp;
            x++;
        }
        copy();
        cout << top << '\n';
    }
}