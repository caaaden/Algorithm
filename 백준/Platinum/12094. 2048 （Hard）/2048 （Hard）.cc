#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int n;
int ans = 2;
const int MAX = 10;
int memo[MAX+1];
void move(vector<vector<int>>& board, int k) {
//    cout << k << '\n';
//    for (int i = 1; i <= n; ++i) {
//        for (int j = 1; j <= n; ++j) {
//            cout << board[i][j] << ' ';
//        }
//        cout << '\n';
//    }
//    cout << '\n';

    int tmpMax = 2;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            tmpMax = max(tmpMax, board[i][j]);
        }
    }
    if (k == MAX) {
        ans = max(ans, tmpMax);
        return;
    }
    if (tmpMax <= (ans >> (10-k))) return;
    vector<vector<int>> newBoard(n+1, vector<int>(n+1));

    // down
    for (int i = 1; i <= n; ++i) {
        int prev = -1, cur = -1, idx = n;
        for (int j = n; j >= 1; --j) {
            if (!board[j][i]) continue;
            if (prev == -1) prev = board[j][i];
            else {
                cur = board[j][i];
                if (cur == prev) {
                    newBoard[idx--][i] = (prev << 1);
                    prev = -1;
                } else {
                    newBoard[idx--][i] = prev;
                    prev = cur;
                }
            }
        }
        if (prev != -1) newBoard[idx--][i] = prev;
//        for (int j = idx; j >= 1; --j) newBoard[j][i] = 0;
    }
    if (board != newBoard) move(newBoard, k+1);

    // up
    for (int i = 1; i <= n; ++i) {
        int prev = -1, cur = -1, idx = 1;
        for (int j = 1; j <= n; ++j) {
            if (!board[j][i]) continue;
            if (prev == -1) prev = board[j][i];
            else {
                cur = board[j][i];
                if (cur == prev) {
                    newBoard[idx++][i] = (prev << 1);
                    prev = -1;
                } else {
                    newBoard[idx++][i] = prev;
                    prev = cur;
                }
            }
        }
        if (prev != -1) newBoard[idx++][i] = prev;
        for (int j = idx; j <= n; ++j) newBoard[j][i] = 0;
    }
    if (board != newBoard) move(newBoard, k+1);

    // right
    for (int i = 1; i <= n; ++i) {
        int prev = -1, cur = -1, idx = n;
        for (int j = n; j >= 1; --j) {
            if (!board[i][j]) continue;
            if (prev == -1) prev = board[i][j];
            else {
                cur = board[i][j];
                if (cur == prev) {
                    newBoard[i][idx--] = (prev << 1);
                    prev = -1;
                } else {
                    newBoard[i][idx--] = prev;
                    prev = cur;
                }
            }
        }
        if (prev != -1) newBoard[i][idx--] = prev;
        for (int j = idx; j >= 1; --j) newBoard[i][j] = 0;
    }
    if (board != newBoard) move(newBoard, k+1);

    // left
    for (int i = 1; i <= n; ++i) {
        int prev = -1, cur = -1, idx = 1;
        for (int j = 1; j <= n; ++j) {
            if (!board[i][j]) continue;
            if (prev == -1) prev = board[i][j];
            else {
                cur = board[i][j];
                if (cur == prev) {
                    newBoard[i][idx++] = (prev << 1);
                    prev = -1;
                } else {
                    newBoard[i][idx++] = prev;
                    prev = cur;
                }
            }
        }
        if (prev != -1) newBoard[i][idx++] = prev;
        for (int j = idx; j <= n; ++j) newBoard[i][j] = 0;
    }
    if (board != newBoard) move(newBoard, k+1);
}

int main() {
    fastio;

    cin >> n;
    vector<vector<int>> board(n+1, vector<int>(n+1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> board[i][j];
            ans = max(ans, board[i][j]);
        }
    }
    move(board, 0);
    cout << ans;
}