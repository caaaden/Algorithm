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
    int numOfBishop = 0;
    int ans = 0;
    vector<int> diag(2*n-1);
    function<void(int, int)> dfs = [&](int k, int depth) {
        if (n-k/2+depth < numOfBishop) return;
        numOfBishop = max(numOfBishop, depth);
        for (int i = k; i < 2*n-1; i += 2) {
            for (int j = 0; j <= i; ++j) {
                int x = j;
                int y = i-j;
                if (x > n-1 || y > n-1) continue;
                if (!board[x][y]) continue;
                if (diag[x-y+n-1]) continue;
                diag[x-y+n-1] = 1;
                dfs(i+2, depth+1);
                diag[x-y+n-1] = 0;
            }
        }
    };
    dfs(0, 0);
    ans += numOfBishop;
    numOfBishop = 0;
    dfs(1, 0);
    ans += numOfBishop;
    cout << ans;
}