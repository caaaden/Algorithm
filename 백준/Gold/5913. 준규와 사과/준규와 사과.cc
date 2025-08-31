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
#define pb push_back

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
using psi = pair<string, int>;
using piii = pair<pii, int>;
using piiii = pair<pii, pii>;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

constexpr int dx[4] = {1, -1, 0, 0};
constexpr int dy[4] = {0, 0, 1, -1};
constexpr int bit = 9;
const long long MOD = 1e9 + 7;
const int MAX = 1e9;

int main() {
    fastio;

    int k; cin >> k;
    vector<vector<int>> board(6, vector<int>(6));
    for (int i = 0; i < k; ++i) {
        int x, y; cin >> x >> y;
        board[x][y] = 1;
    }
    int cnt = 0;
    vector<vector<int>> vis(6, vector<int>(6));
    vis[1][1] = 1;

    function<void(int, int, int)> backtrack = [&](int d, int x, int y) {
        if (d == 24-k) {
            if (x == 5 && y == 5) cnt++;
            return;
        }
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 1 || nx > 5 || ny < 1 || ny > 5) continue;
            if (board[nx][ny]) continue;
            if (vis[nx][ny]) continue;
            vis[nx][ny] = 1;
            backtrack(d+1, nx, ny);
            vis[nx][ny] = 0;
        }
    };

    backtrack(0, 1, 1);
    cout << cnt;
}

