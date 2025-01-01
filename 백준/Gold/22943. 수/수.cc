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

int board[10][10];
int main() {
    fastio;

    auto isDuplicate = [](int x) {
        vector<int> check(10);
        while (x) {
            int r = x % 10;
            if (check[r]) return true;
            check[r] = 1;
            x /= 10;
        }
        return false;
    };
    int k, m;
    cin >> k >> m;
    constexpr int MAX = 100000;
    vector<bool> isPrime(MAX, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i*i < MAX; ++i) {
        if (!isPrime[i]) continue;
        for (int j = i*i; j < MAX; j += i) isPrime[j] = false;
    }
    vector<int> primes;
    primes.reserve(10000);
    for (int i = 2; i < MAX; ++i) {
        if (isPrime[i]) primes.push_back(i);
    }
    vector<int> check(MAX);
    for (int i = 0; i < primes.size()-1; ++i) {
        for (int j = i+1; j < primes.size(); ++j) {
            int sum = primes[i] + primes[j];
            if (sum >= MAX) break;
            check[sum] = 1;
        }
    }
    int cnt = 0;
    int ceiling = 1;
    for (int i = 0; i < k; ++i) ceiling *= 10;
    vector<int> check2(MAX);
    for (int i = ceiling/10; i < ceiling; ++i) {
        if (!check[i]) continue;
        if (isDuplicate(i)) continue;
        int e = i;
        while (e % m == 0) e /= m;
        if (check2[e]) {
            cnt++;
            continue;
        }
        for (auto& prime : primes) {
            if (prime >= e) break;
            if (e % prime) continue;
            int q = e / prime;
            if (isPrime[q]) {
                check2[e] = 1;
                cnt++;
                break;
            }
        }
    }
    cout << cnt;
}

