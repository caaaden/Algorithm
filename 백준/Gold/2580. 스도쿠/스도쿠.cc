#include <bits/stdc++.h>
using namespace std;
int board[9][9], row[9][10], col[9][10], box[9][10], cnt;
bool isDone; // default: false

void solve(int n) {
    if (n == cnt) {
        // board에 더 이상 0이 존재하지 않을 때, 즉 스도쿠가 완성되었을 때,
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                cout << board[i][j] << ' ';
            }
            cout << '\n';
        }
        isDone = true;
        return;
    }
    
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (board[i][j]) continue; // board에 값이 있으면,
            int x = (i/3)*3+(j/3);
            for (int k = 1; k <= 9; ++k) {
                if (!row[i][k] && !col[j][k] && !box[x][k]) {
                    board[i][j] = k;
                    row[i][k] = 1;
                    col[j][k] = 1;
                    box[x][k] = 1;
                    solve(n+1);
                    if (isDone) return;
                    board[i][j] = 0;
                    row[i][k] = 0;
                    col[j][k] = 0;
                    box[x][k] = 0;
                }
            }
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cin >> board[i][j];
            if (!board[i][j]) {
                cnt++;
                continue;
            }
            row[i][board[i][j]] = 1;
            col[j][board[i][j]] = 1;
            box[(i/3)*3+(j/3)][board[i][j]] = 1;
        }
    }
    solve(0);
}