#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main() {
    fastio;

    int n;
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> board[i][j];
        }
    }
    int white = 0, black = 0;
    vector<int> diag(2*n-1);
    function<void(int, int)> dfs = [&](int k, int depth) {
        if (n-k/2+depth < white) return;
        white = max(white, depth);
        for (int i = k; i < 2*n-1; ++i) {
            if (i & 1) continue;
            for (int j = 0; j <= i; ++j) {
                int x = j;
                int y = i-j;
                if (x > n-1 || y > n-1) continue;
                if (!board[x][y]) continue;
                if (diag[x-y+n-1]) continue;
                diag[x-y+n-1] = 1;
                dfs(i+1, depth+1);
                diag[x-y+n-1] = 0;
            }
        }
    };
    function<void(int, int)> dfs2 = [&](int k, int depth) {
        if (n-k/2+depth < black) return;
        black = max(black, depth);
        for (int i = k; i < 2*n-1; ++i) {
            if (!(i & 1)) continue;
            for (int j = 0; j <= i; ++j) {
                int x = j;
                int y = i-j;
                if (x > n-1 || y > n-1) continue;
                if (!board[x][y]) continue;
                if (diag[x-y+n-1]) continue;
                diag[x-y+n-1] = 1;
                dfs2(i+1, depth+1);
                diag[x-y+n-1] = 0;
            }
        }
    };
    dfs(0, 0);
    dfs2(0, 0);
    cout << white+black;
}