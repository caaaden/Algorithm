#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define pb push_back
#define X first
#define Y second
using namespace __gnu_pbds;
using namespace std;
using pii = pair<int, int>;
using ll = long long;
typedef tree<int, null_type, greater_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int dp[10001];
pii candy[5001];
int main() {
    fastio;


    while (true) {
        int n;
        double tmp;
        cin >> n >> tmp;
        int m = (int)(tmp*100+0.5);
        if (!n && !m) break;
        for (int i = 1; i <= n; ++i) {
            cin >> candy[i].first;
            cin >> tmp;
            candy[i].second = (int)(tmp*100+0.5);
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = candy[i].Y; j <= m; ++j) {
                dp[j] = max(dp[j], dp[j-candy[i].Y]+candy[i].X);
            }
        }
        cout << dp[m] << '\n';
        memset(dp, 0, sizeof(dp));
    }
}