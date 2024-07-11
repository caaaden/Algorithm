#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
using pii = pair<int, int>;

int n;
vector<vector<int>> pops;
void district(int& x, int& y, int& d1, int& d2, vector<vector<int>>& board) {
    int l = y, r = y;
    for (int i = x; i <= x+d1+d2; ++i) {
        for (int j = l; j <= r; ++j) board[i][j] = 5;
        if (i < x+d1) l--;
        else l++;
        if (i < x+d2) r++;
        else r--;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (board[i][j] == 5) continue;
            if (i < x+d1 && j <= y) board[i][j] = 1;
            else if (i <= x+d2 && j > y) board[i][j] = 2;
            else if (i >= x+d1 && j < y-d1+d2) board[i][j] = 3;
            else board[i][j] = 4;
        }
    }
}

int getPopulationDifference(vector<vector<int>>& board) {
    vector<int> cnt(5);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int constituency = board[i][j];
            cnt[constituency-1] += pops[i][j];
        }
    }
    sort(cnt.begin(), cnt.end());
    return cnt.back() - cnt.front();
}

int main() {
    fastio;

    cin >> n;
    pops.resize(n+1, vector<int>(n+1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> pops[i][j];
        }
    }
    int ans = INT_MAX;
    for (int x = 1; x <= n; ++x) {
        for (int y = 1; y <= n; ++y) {
            for (int d1 = 1; d1 <= y-1; ++d1) {
                for (int d2 = 1; d2 <= n-y; ++d2) {
                    if (d1 + d2 > n-x) break;
                    vector<vector<int>> board(n+1, vector<int>(n+1));
                    district(x, y, d1, d2, board);
                    ans = min(ans, getPopulationDifference(board));
                }
            }
        }
    }
    cout << ans;
}