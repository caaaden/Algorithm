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

int main(){
    fastio;

    vector<vector<int>> board(5, vector<int>(5));
    for (int i = 1; i < 5; ++i) cin >> board[0][i];
    for (int i = 1; i < 5; ++i) cin >> board[i][0];
    int ans = 0;
//    vector<bool> vis(14);
    int vis = 0;
    vector<pii> base = {{2, 2}, {2, 3}, {2, 4}, {3, 2}, {3, 3}, {4, 2}};

    auto isNotInRange = [](int x) {
        return x < 1 || x > 13;
    };

    auto fillAndCheck = [&]() {
        int tempVis = vis; // copy vis

        board[1][2] = board[0][2] - (board[2][2] + board[3][2] + board[4][2]);
        if (isNotInRange(board[1][2]) || tempVis & (1 << board[1][2])) return false;
        tempVis |= (1 << board[1][2]);

        board[1][3] = board[0][3] - (board[2][3] + board[3][3]);
        if (isNotInRange(board[1][3]) || tempVis & (1 << board[1][3])) return false;
        tempVis |= (1 << board[1][3]);

        board[1][4] = board[0][4] - board[2][4];
        if (isNotInRange(board[1][4]) || tempVis & (1 << board[1][4])) return false;
        tempVis |= (1 << board[1][4]);

        board[2][1] = board[2][0] - (board[2][2] + board[2][3] + board[2][4]);
        if (isNotInRange(board[2][1]) || tempVis & (1 << board[2][1])) return false;
        tempVis |= (1 << board[2][1]);

        board[3][1] = board[3][0] - (board[3][2] + board[3][3]);
        if (isNotInRange(board[3][1]) || tempVis & (1 << board[3][1])) return false;
        tempVis |= (1 << board[3][1]);

        board[4][1] = board[4][0] - board[4][2];
        if (isNotInRange(board[4][1]) || tempVis & (1 << board[4][1])) return false;
        tempVis |= (1 << board[4][1]);

        board[1][1] = board[1][0] - (board[1][2] + board[1][3] + board[1][4]);
        if (isNotInRange(board[1][1])) return false;
        if (board[1][1] != board[0][1] - (board[2][1] + board[3][1] + board[4][1])) return false;
        if (tempVis & (1 << board[1][1])) return false;
//        tempVis[board[1][1]] = true;

        return true;
    };

    function<void(int)> dfs = [&](int d) {
        if (d == 6) {
            ans += fillAndCheck();
            return;
        }
        for (int i = 1; i <= 13; ++i) {
            if (vis & (1 << i)) continue;
            vis |= 1 << i;
            board[base[d].X][base[d].Y] = i;
            dfs(d+1);
            board[base[d].X][base[d].Y] = 0;
            vis &= ~(1 << i);
        }
    };

    dfs(0);
    cout << ans;
}