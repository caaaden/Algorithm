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
    vector<vector<vector<int>>> boardAssigned(10, vector<vector<int>>(9, vector<int>(9)));
    bool found = false;

    auto mark = [&](int num, int x, int y) {
        // 행, 열, 박스에 대해 체크
        for (int i = 0; i < 9; ++i) {
            boardAssigned[num][x][i] = 1;
            boardAssigned[num][i][y] = 1;
        }
        int sx = (x / 3) * 3;
        int sy = (y / 3) * 3;
        for (int i = sx; i < sx+3; ++i) {
            for (int j = sy; j < sy+3; ++j) {
                boardAssigned[num][i][j] = 1;
            }
        }
    };

    auto fillCells = [&]() {
        // naked single or hidden single 채우기
        // 하나라도 찾으면 계속 돌리기
        // 각 숫자에 대해 그 숫자가 더 이상 들어갈 수 없는 공간을 표시하는 board 만들기
        // boardAssigned[x][y][z] = 숫자 x가 (y, z)에 들어갈 수 있는가?
        // 다른 숫자가 이미 있으면 넣을 수 없음. 즉 빈 칸이 아닌 곳은 모두 체크,

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
                            // i, j에 __builtn_ctz(~x) 채우기
                            mark(__builtin_ctz(~x), i, j);
                        }
                    }
                }
            }
            // cross hatching 적용
            // 어떤 숫자에 대해,
            // 모든 박스에 대해,
            for (int i = 1; i <= 9; ++i) {
                for (int sx = 0; sx < 9; sx += 3) {
                    for (int sy = 0; sy < 9; sy += 3) {
                        // sx, sy
                        vector<pii> cands; // i의 해당 박스의 후보지
                        for (int j = sx; j < sx+3; ++j) {
                            for (int k = sy; k < sy+3; ++k) {
                                // board[j][k]가 빈 칸이면서, boardAssigned[i][j][k] = 0인 곳이 하나밖에 없을 때
                                if (board[j][k] > 1) continue;
                                if (boardAssigned[i][j][k]) continue;
                                cands.push_back({j, k});
                            }
                        }
                        // cands.size() != 1 : 후보지가 두 곳 이상 or 없으므로 탈락
                        if (cands.size() != 1) continue;
                        found2 = true;
                        auto [x, y] = cands[0];
                        board[x][y] = (1 << i);
                        mark(i, x, y);
                        check[0][x] |= board[x][y];
                        check[1][y] |= board[x][y];
                        check[2][getBoxIdx(x, y)] |= board[x][y];
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
            if (c == '0') continue;
            mark(c-'0', i, j);
        }
    }
    fillCells(); // 논리적으로 naked single or hidden single을 찾아서 채우기
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