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

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

constexpr int dx[4] = {1, -1, 0, 0};
constexpr int dy[4] = {0, 0, 1, -1};
constexpr int bit = 9;
constexpr int MOD = 1e9;

int main()
{
    fastio;
    
    int a, b, k;
    cin >> a >> b >> k;
    if (k < a) {
        cout << 0;
        return 0;
    }
    const int MAX = min(b, k);
    // ~b
    vector<bool> isPrime(MAX+1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i*i <= MAX; ++i) {
        if (!isPrime[i]) continue;
        for (int j = i*i; j <= MAX; j += i) isPrime[j] = false;
    }
    // a~b
    vector<int> primes;
    for (int i = a; i <= MAX; ++i) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }
    map<int, ll, greater<>> dp;
    dp[0] = 1;
    for (auto& p : primes) {
        for (auto it = dp.begin(); it != dp.end(); ++it) {
            int val = it->first + p;
            if (val <= k) dp[val] += it->second;
        }
    }
    cout << dp[k];
    // 2, 3, 5, 7, 11
    // int n = primes.size();
    // if (b <= 100000) {
        
    // } else {
    //     // bitmasking + bruteforcing
    //     int ans = 0;
    //     for (int i = 0; i < (1 << n); ++i) {
    //         int sum = 0;
    //         for (int j = 0; j < n; ++j) {
    //             if (i & (1 << j)) {
    //                 sum += primes[j];
    //             }
    //         }
    //         if (sum == k) ans++;
    //     }
    //     cout << ans;
    // }
}