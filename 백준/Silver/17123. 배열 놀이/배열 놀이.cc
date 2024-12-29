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
        vector<int> rows(n+1), cols(n+1);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                cin >> board[i][j];
                rows[i] += board[i][j];
                cols[j] += board[i][j];
            }
        }
        while (m--) {
            int r1, c1, r2, c2, v;
            cin >> r1 >> c1 >> r2 >> c2 >> v;
            for (int i = r1; i <= r2; ++i) rows[i] += (c2 - c1 + 1) * v;
            for (int i = c1; i <= c2; ++i) cols[i] += (r2 - r1 + 1) * v;
        }
        for (int i = 1; i <= n; ++i) cout << rows[i] << ' ';
        cout << '\n';
        for (int i = 1; i <= n; ++i) cout << cols[i] << ' ';
        cout << '\n';
    }
}