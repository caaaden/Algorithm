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

    int n;
    cin >> n;
    vector<vector<ll>> dp(n+1, vector<ll>(2));
    dp[1][0] = 24;
    dp[1][1] = 2;
    for (int i = 2; i <= n; ++i) {
        dp[i][0] = dp[i-1][0] * 24 + dp[i-1][1] * 2;
        dp[i][0] %= MOD;
        dp[i][1] = dp[i-1][0] * 2 + dp[i-1][1] * 24;
        dp[i][1] %= MOD;
    }
    cout << dp[n][0];
}