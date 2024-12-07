#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0);
#define all(v) v.begin(), v.end()
#define X first
#define Y second
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using piii = pair<int, pii>;

int main() {
    fastio;

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> pSum(n);
        cin >> pSum[0];
        for (int i = 1; i < n; ++i) {
            int x;
            cin >> x;
            pSum[i] = pSum[i-1] + x;
        }
        vector<vector<int>> dp(n+1, vector<int>(n+1, INT_MAX));
        vector<vector<int>> A(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 0;
            A[i][i] = i;
        }
        for (int len = 1; len < n; ++len) {
            for (int i = 0; i+len < n; ++i) {
                int j = i + len;
                // A[i][j-1] <= A[i][j] <= A[i+1][j]
                for (int k = A[i][j-1]; k <= A[i+1][j]; ++k) {
//                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + pSum[j] - (i ? pSum[i-1] : 0));
                    int tmp = dp[i][k] + dp[k+1][j];
                    if (dp[i][j] > tmp) {
                        dp[i][j] = tmp;
                        A[i][j] = k;
                    }
                }
                dp[i][j] += pSum[j] - (i ? pSum[i-1] : 0);
            }
        }
        cout << dp[0][n-1] << '\n';
    }
}