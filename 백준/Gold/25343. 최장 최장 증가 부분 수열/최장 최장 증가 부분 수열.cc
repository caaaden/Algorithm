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

    int n; cin >> n;
    vector<vector<int>> board(n+1, vector<int>(n+1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> board[i][j];
        }
    }
    vector<vector<int>> dp(n+1, vector<int>(n+1));

    auto updateTable = [&](int x, int y) {
        dp[x][y] = 1;
        for (int i = 1; i <= x; ++i) {
            for (int j = 1; j <= y; ++j) {
                if (i == x && j == y) continue;
                if (board[i][j] >= board[x][y]) continue;
                dp[x][y] = max(dp[x][y], dp[i][j]+1);
            }
        }
    };

    int ans = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            updateTable(i, j);
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans;
}

