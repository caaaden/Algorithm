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

    // dp[n][n] = ?
    auto getDigitCount = [](int x) {
        int ret = 0;
        while (x) {
            ret++;
            x /= 10;
        }
        return ret;
    };

    // int x = 13;
    // int y = 254;
    // int combNum = x;
    // for (int i = 0; i < getDigitCount(y); ++i) {
    //     combNum *= 10;
    // }
    // combNum += y;
    // cout << combNum;

    vector<bool> isPrime(1000000, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i*i <= 1000000; ++i) {
        if (!isPrime[i]) continue;
        for (int j = i*i; j <= 1000000; j += i) {
            isPrime[j] = false;
        }
    }

    int n;
    cin >> n;
    vector<vector<int>> dp(n+1, vector<int>(n+1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int combNum = i;
            int digitCount = getDigitCount(j);
            for (int k = 0; k < digitCount; ++k) {
                combNum *= 10;
            }
            combNum += j;
            if (i == 1 && j == 1) continue;
            if (i == 1) {
                dp[i][j] = dp[i][j-1] + isPrime[combNum];
            } else if (j == 1) {
                dp[i][j] = dp[i-1][j] + isPrime[combNum];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + isPrime[combNum];
            }
        }
    }
    cout << dp[n][n];
}