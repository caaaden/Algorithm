#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main() {
    fastio;

    int n, m; // 앱의 수, 필요한 메모리
    cin >> n >> m;
    vector<int> v(n+1);
    for (int i = 1; i <= n; ++i) cin >> v[i];
    vector<int> c(n+1); // cost
    for (int i = 1; i <= n; ++i) cin >> c[i];
    // 101, 10001
    vector<vector<int>> dp(n+1, vector<int>(10001));
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= 10000; ++j) {
            // 각 앱의 모든 비용에 대하여,
            // c[i]
            // j >= c[i]
            if (j >= c[i]) dp[i][j] = max(dp[i-1][j], dp[i-1][j-c[i]]+v[i]);
            else dp[i][j] = dp[i-1][j]; //
            if (i == n) {
                if (dp[i][j] >= m) {
                    cout << j;
                    return 0;
                }
            }
        }
    }
}