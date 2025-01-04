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

    int n, x;
    cin >> n >> x;
    vector<int> dp(x+1), tdp(x+1);
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
        int l, c;
        cin >> l >> c;
        for (int j = 0; j <= x; ++j) {
            tdp[j] = dp[j];
            if (j >= l) tdp[j] += tdp[j-l];
            if (j >= l*(c+1)) tdp[j] -= dp[j-l*(c+1)];
        }
        for (int j = 0; j <= x; ++j) dp[j] = tdp[j];
    }
    cout << dp[x];
}