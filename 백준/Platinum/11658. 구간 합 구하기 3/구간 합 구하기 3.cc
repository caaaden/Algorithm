#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> bit;
int query(int i, int j) {
    int sum = 0;
    while (i > 0) {
        int tmp = j;
        while (tmp > 0) {
            sum += bit[i][tmp];
            tmp -= (tmp & -tmp);
        }
        i -= (i & -i);
    }
    return sum;
}

void update(int i, int j, int diff) {
    while (i <= n) {
        int tmp = j;
        while (tmp <= n) {
            bit[i][tmp] += diff;
            tmp += (tmp & -tmp);
        }
        i += (i & -i);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    vector<vector<int>> board(n+1, vector<int>(n+1));
    bit.resize(n+1, vector<int>(n+1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> board[i][j];
            update(i, j, board[i][j]);
        }
    }
    while (m--) {
        int w;
        cin >> w;
        if (!w) {
            int x, y, c;
            cin >> x >> y >> c;
            int diff = c - board[x][y];
            board[x][y] = c;
            update(x, y, diff);
        } else {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            cout << query(x2, y2) - query(x1-1, y2) - query(x2, y1-1) + query(x1-1, y1-1) << '\n';
        }
    }
}