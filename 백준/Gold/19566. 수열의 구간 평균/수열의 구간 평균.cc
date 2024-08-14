#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
using i64 = long long;

int main() {
    fastio;

    i64 n, k;
    cin >> n >> k;
    unordered_map<i64, int> dp;
    i64 ans = 0;
    i64 sum = 0;
    for (i64 i = 0; i < n; ++i) {
        i64 x;
        cin >> x;
        sum += x;
        ans += dp[sum-(i+1)*k]++;
    }
    ans += dp[0];
    cout << ans;
}