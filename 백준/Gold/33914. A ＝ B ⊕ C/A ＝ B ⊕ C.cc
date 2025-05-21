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

    vector<vector<ll>> dp(2001, vector<ll>(2001, -1));
    function<ll(int, int)> comb = [&](int n, int r) {
        if (r == 0 || r == n) return 1LL;
        if (dp[n][r] != -1) return dp[n][r];
        return dp[n][r] = (comb(n-1, r-1) + comb(n-1, r)) % MOD;
    };
    int x, y;
    cin >> x >> y;
    if (x & 1) {
        cout << 0;
        return 0;
    }
    if (y*2-x < 0 || (y*2-x) % 6) {
        cout << 0;
        return 0;
    }
    int a = x / 2;
    int b = (y*2-x) / 6;
    ll ans = comb(a+b, b);
    for (int i = 0; i < a; ++i) {
        ans *= 3;
        ans %= MOD;
    }
    cout << ans;
}