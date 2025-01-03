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

    map<int, int> candies;
    int n;
    cin >> n;
    int limit = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        limit += x;
        candies[x]++;
    }
    vector<ll> dp(limit+1);
    dp[0] = 1;
    if (candies.count(0)) dp[0] += candies[0];
    for (auto& [price, quantity] : candies) {
        if (!price) continue;
        for (int i = limit; i >= price; --i) {
            int accumulated = 0;
            for (int j = 0; j < quantity; ++j) {
                accumulated += price;
                if (i < accumulated) break;
                dp[i] += dp[i - accumulated];
            }
        }
    }
    vector<bool> isPrime(limit+1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i*i <= limit; ++i) {
        if (!isPrime[i]) continue;
        for (int j = i*i; j <= limit; j += i) isPrime[j] = false;
    }
    ll ans = 0;
    for (int i = 2; i <= limit; ++i) {
        if (!isPrime[i]) continue;
        ans += dp[i];
    }
    cout << ans;
}