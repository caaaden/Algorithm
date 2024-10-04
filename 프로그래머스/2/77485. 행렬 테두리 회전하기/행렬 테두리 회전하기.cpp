#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    int n = rows;
    int m = columns;
    vector<vector<int>> board(n+1, vector<int>(m+1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            board[i][j] = (i-1) * m + j;
        }
    }
    vector<int> ans;
    for (auto& q : queries) {
        int x1 = q[0], y1 = q[1];
        int x2 = q[2], y2 = q[3];
        int tmp = board[x1][y1];
        int mmin = INT_MAX;
        for (int i = x1+1; i <= x2; ++i) {
            mmin = min(mmin, board[i][y1]);
            board[i-1][y1] = board[i][y1];
        }
        for (int i = y1+1; i <= y2; ++i) {
            mmin = min(mmin, board[x2][i]);
            board[x2][i-1] = board[x2][i];
        }
        for (int i = x2-1; i >= x1; --i) {
            mmin = min(mmin, board[i][y2]);
            board[i+1][y2] = board[i][y2];
        }
        for (int i = y2-1; i >= y1+1; --i) {
            mmin = min(mmin, board[x1][i]);
            board[x1][i+1] = board[x1][i];
        }
        mmin = min(mmin, tmp);
        board[x1][y1+1] = tmp;
        ans.push_back(mmin);
    }
    return ans;
}