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
    
    int n;
    cin >> n;
    vector<int> v(n+1);
    for (int i = 0; i < n-1; ++i) {
        int tmp;
        cin >> v[i] >> tmp;
    }
    cin >> v[n-1] >> v[n];
    vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
    for (int i = 0; i < n; ++i) dp[i][i] = 0;
    for (int len = 1; len < n; ++len) {
        for (int i = 0; i+len < n; ++i) {
            int j = i + len;
            for (int k = i; k < j; ++k) dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + v[i] * v[k+1] * v[j+1]);
        }
    }
    cout << dp[0][n-1];
}