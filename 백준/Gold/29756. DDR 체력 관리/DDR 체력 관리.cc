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

    // dp[a+1][min(100, b+10)] = max(self, dp[a][b])
    // dp[a+1][min(100, b+10) - h[a+1]] = max(self, dp[a][b] + s[a+1])
    int n, k;
    cin >> n >> k;
    vector<int> s(n+1), h(n+1);
    rep(i, 1, n+1) cin >> s[i];
    rep(i, 1, n+1) cin >> h[i];
    vector<vector<int>> dp(n+1, vector<int>(101));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= 100; ++j) {
            // i : 구간, j : 체력
            int hp = min(100, j+k); // 회복된 체력
            dp[i+1][hp] = max(dp[i+1][min(100, j+k)], dp[i][j]); // 선택 x, 체력 회복만
            if (hp >= h[i+1]) dp[i+1][hp - h[i+1]] = max(dp[i+1][hp - h[i+1]], dp[i][j] + s[i+1]); // 선택 o
        }
    }
    // dp[n][0...100] 중 최댓값
    int ans = 0;
    for (int i = 0; i <= 100; ++i) ans = max(ans, dp[n][i]);
    cout << ans;
}