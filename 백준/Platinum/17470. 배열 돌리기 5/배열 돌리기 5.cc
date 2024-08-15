#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int n, m, r;
void operate1(vector<vector<int>>& board) {
    int r = board.size();
    int c = board[0].size();
    for (int i = 0; i < c; ++i) {
        int half = r / 2;
        for (int j = 0; j < half; ++j) {
            swap(board[j][i], board[r-1-j][i]);
        }
    }
}

void operate2(vector<vector<int>>& board) {
    int r = board.size();
    int c = board[0].size();
    for (int i = 0; i < r; ++i) {
        int half = c / 2;
        for (int j = 0; j < half; ++j) {
            swap(board[i][j], board[i][c-1-j]);
        }
    }
}

void operate3(vector<vector<int>>& board) {
    int r = board.size();
    int c = board[0].size();
    vector<vector<int>> tmp(c, vector<int>(r));
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            tmp[j][r-1-i] = board[i][j];
        }
    }
    board = tmp;
}

void operate4(vector<vector<int>>& board) {
    int r = board.size();
    int c = board[0].size();
    vector<vector<int>> tmp(c, vector<int>(r));
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            tmp[c-1-j][i] = board[i][j];
        }
    }
    board = tmp;
}

void operate5(vector<vector<int>>& board) {
    int r = board.size();
    int c = board[0].size();
    vector<vector<int>> tmp(r, vector<int>(c));
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (i < r/2) {
                if (j < c/2) {
                    tmp[i][j+c/2] = board[i][j];
                } else {
                    tmp[i+r/2][j] = board[i][j];
                }
            } else {
                if (j >= c/2) {
                    tmp[i][j-c/2] = board[i][j];
                } else {
                    tmp[i-r/2][j] = board[i][j];
                }
            }
        }
    }
    board = tmp;
}

void operate6(vector<vector<int>>& board) {
    int r = board.size();
    int c = board[0].size();
    vector<vector<int>> tmp(r, vector<int>(c));
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (i < r/2) {
                if (j < c/2) {
                    tmp[i+r/2][j] = board[i][j];
                } else {
                    tmp[i][j-c/2] = board[i][j];
                }
            } else {
                if (j >= c/2) {
                    tmp[i-r/2][j] = board[i][j];
                } else {
                    tmp[i][j+c/2] = board[i][j];
                }
            }
        }
    }
    board = tmp;
}

int main() {
    fastio;

    cin >> n >> m >> r;
    vector<vector<int>> board(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }
    vector<vector<int>> origin = board;
    set<vector<vector<int>>> s;
    s.insert(board);
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(1, 6);
    for (int i = 0; i < 1000; ++i) {
        auto what = dist(mt);
        if (what == 1) operate1(board);
        else if (what == 2) operate2(board);
        else if (what == 3) operate3(board);
        else if (what == 4) operate4(board);
        else if (what == 5) operate5(board);
        else operate6(board);
        s.insert(board);
    }
    vector<vector<vector<int>>> v(s.begin(), s.end());
    vector<vector<int>> tbl(32, vector<int>(6));
    for (int i = 0; i < 32; ++i) {
        vector<vector<int>> tmp;

        tmp = v[i];
        operate1(tmp);
        for (int j = 0; j < 32; ++j) {
            if (tmp == v[j]) {
                tbl[i][0] = j;
                break;
            }
        }

        tmp = v[i];
        operate2(tmp);
        for (int j = 0; j < 32; ++j) {
            if (tmp == v[j]) {
                tbl[i][1] = j;
                break;
            }
        }

        tmp = v[i];
        operate3(tmp);
        for (int j = 0; j < 32; ++j) {
            if (tmp == v[j]) {
                tbl[i][2] = j;
                break;
            }
        }

        tmp = v[i];
        operate4(tmp);
        for (int j = 0; j < 32; ++j) {
            if (tmp == v[j]) {
                tbl[i][3] = j;
                break;
            }
        }

        tmp = v[i];
        operate5(tmp);
        for (int j = 0; j < 32; ++j) {
            if (tmp == v[j]) {
                tbl[i][4] = j;
                break;
            }
        }

        tmp = v[i];
        operate6(tmp);
        for (int j = 0; j < 32; ++j) {
            if (tmp == v[j]) {
                tbl[i][5] = j;
                break;
            }
        }
    }
    int now;
    for (int i = 0; i < 32; ++i) {
        if (origin == v[i]) {
            now = i;
            break;
        }
    }
    while (r--) {
        int op;
        cin >> op;
        int next = tbl[now][op-1];
        now = next;
    }
    vector<vector<int>> ans = v[now];
    for (int i = 0; i < ans.size(); ++i) {
        for (int j = 0; j < ans[0].size(); ++j) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
}