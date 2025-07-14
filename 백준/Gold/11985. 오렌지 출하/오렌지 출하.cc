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

    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> v(n);
    for (auto& e : v) cin >> e;
    vector<ll> dp(n, LLONG_MAX);
    dp[0] = k;
    for (int i = 1; i < n; ++i) {
        ll mx = 0, mn = INT_MAX;
        for (int j = i-1; j >= max(-1, i-m); --j) {
            mx = max(mx, v[j+1]);
            mn = min(mn, v[j+1]);
            dp[i] = min(dp[i], (j == -1 ? 0 : dp[j]) + k + (mx-mn) * (i-j));
        }
    }
    cout << dp[n-1];
}