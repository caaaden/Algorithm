#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

#define fastio ios::sync_with_stdio(0), cin.tie(0);
#define all(v) v.begin(), v.end()
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
using piii = pair<int, pii>;
using piiii = pair<pii, pii>;

template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

constexpr int dx[4] = {1, -1, 0, 0};
constexpr int dy[4] = {0, 0, 1, -1};
constexpr int bit = 9;

int main() {
    fastio;

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> board(n+1, vector<int>(n+1));
        rep(i, 1, n+1) rep(j, 1, n+1) cin >> board[i][j];
        vector<vector<int>> imos(n+2, vector<int>(n+2));
        for (int i = 0; i < m; ++i) {
            int r1, c1, r2, c2, v;
            cin >> r1 >> c1 >> r2 >> c2 >> v;
            imos[r1][c1] += v;
            imos[r1][c2+1] -= v;
            imos[r2+1][c1] -= v;
            imos[r2+1][c2+1] += v;
        }
        for (int i = 1; i <= n+1; ++i) {
            for (int j = 1; j <= n; ++j) {
                imos[i][j+1] += imos[i][j];
            }
        }
        for (int i = 1; i <= n+1; ++i) {
            for (int j = 1; j <= n; ++j) {
                imos[j+1][i] += imos[j][i];
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                board[i][j] += imos[i][j];
            }
        }
        for (int i = 1; i <= n; ++i) {
            int sum = 0;
            for (int j = 1; j <= n; ++j) {
                sum += board[i][j];
            }
            cout << sum << ' ';
        }
        cout << '\n';
        for (int i = 1; i <= n; ++i) {
            int sum = 0;
            for (int j = 1; j <= n; ++j) {
                sum += board[j][i];
            }
            cout << sum << ' ';
        }
        cout << '\n';
    }
}