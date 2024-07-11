#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
using pii = pair<int, int>;

int n;
vector<vector<int>> pops;
void district(int x, int y, int d1, int d2, vector<vector<int>>& board) {
    // x, y, d1, d2에 따른 선거구 구획
    // on the 'board'
    int l = y, r = y; // 왼쪽 끝지점, 오른쪽 끝지점
    for (int i = x; i <= x+d1+d2; ++i) {
        // 선거구 board에 번호 적기
        // l...r
        for (int j = l; j <= r; ++j) board[i][j] = 5;
        if (i < x+d1) l--;
        else l++;
        if (i < x+d2) r++;
        else r--;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (board[i][j] == 5) continue;
            if (i < x+d1 && j <= y) {
                board[i][j] = 1;
            } else if (i <= x+d2 && j > y) {
                board[i][j] = 2;
            } else if (i >= x+d1 && j < y-d1+d2) {
                board[i][j] = 3;
            } else {
                board[i][j] = 4;
            }
        }
    }
}

int getPopulationDifference(vector<vector<int>>& board) {
    // 인구가 가장 많은 선거구와 가장 적은 선거구 인구의 인구 차이를 리턴
    vector<int> cnt(6);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int constituency = board[i][j]; // 1~5
            cnt[constituency] += pops[i][j];
        }
    }
    vector<int> v;
    v.reserve(5);
    for (int i = 1; i <= 5; ++i) v.push_back(cnt[i]);
    sort(v.begin(), v.end());
    return v.back() - v.front();
}

int main() {
    fastio;

    // 진짜 구현 벌써부터 개 어지럽네 시팔
    // x, y, d1, d2
    // 우선 선거구 5를 board에 표시부터.
    // 어휘력의 한계가 내가 아는 세상의 한계.

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

//    for (int i = 1; i <= n; ++i) {
//        for (int j = 1; j <= n; ++j) {
//            cout << board[i][j] << ' ';
//        }
//        cout << '\n';
//    }
}