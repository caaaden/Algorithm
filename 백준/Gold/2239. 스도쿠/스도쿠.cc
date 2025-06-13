#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

#define fastio ios::sync_with_stdio(0), cin.tie(0)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define X first
#define Y second
#define rep(i, a, b) for (int i = a; i < b; ++i)

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using psi = pair<string, int>;
using piii = pair<int, pii>;
using piiii = pair<pii, pii>;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

constexpr int dx[4] = {1, -1, 0, 0};
constexpr int dy[4] = {0, 0, 1, -1};
constexpr int bit = 9;
const long long MOD = 1e9 + 7;

int main() {
    fastio;

    auto getBoxIdx = [](int i, int j) {
        return (i/3)*3+(j/3);
    };

    vector<vector<int>> board(9, vector<int>(9));
    vector<pii> emptyCells;
    vector<vector<int>> check(3, vector<int>(9)); // row, col, box
    bool found = false;

    auto fillNakedSingle = [&]() {
        // naked single 채우기
        // 하나라도 찾으면 계속 돌리기
        bool found2 = true;
        while (found2) {
            found2 = false;
            for (int i = 0; i < 9; ++i) {
                for (int j = 0; j < 9; ++j) {
                    if (board[i][j] == 1) {
                        int x = check[0][i] | check[1][j] | check[2][getBoxIdx(i, j)];
                        if (__builtin_popcount(x) == 9) {
                            found2 = true;
                            board[i][j] = (1 << __builtin_ctz(~x));
                            check[0][i] |= board[i][j];
                            check[1][j] |= board[i][j];
                            check[2][getBoxIdx(i, j)] |= board[i][j];
                        }
                    }
                }
            }
        }
    };
    function<void(int)> dfs = [&](int d) {
        if (d == emptyCells.size()) {
            found = true;
            return;
        }
        auto [x, y] = emptyCells[d];
        for (int i = (1 << 1); i <= (1 << 9); i <<= 1) {
            if (check[0][x] & i) continue;
            if (check[1][y] & i) continue;
            if (check[2][getBoxIdx(x, y)] & i) continue;
            board[x][y] = i;
            check[0][x] |= i;
            check[1][y] |= i;
            check[2][getBoxIdx(x, y)] |= i;
            dfs(d+1);
            if (found) return;
            check[0][x] &= ~i;
            check[1][y] &= ~i;
            check[2][getBoxIdx(x, y)] &= ~i;
            board[x][y] = 1;
        }
    };

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            char c;
            cin >> c;
            board[i][j] = 1 << (c-'0');
            check[0][i] |= board[i][j];
            check[1][j] |= board[i][j];
            check[2][getBoxIdx(i, j)] |= board[i][j];
        }
    }
    fillNakedSingle();
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (board[i][j] == 1) {
                emptyCells.push_back({i, j});
            }
        }
    }
    dfs(0);
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cout << __builtin_ctz(board[i][j]);
        }
        cout << '\n';
    }
}