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

    const int MAX = 1e6; // 100만,
    vector<bool> isPrime(MAX+1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i*i <= MAX; ++i) {
        if (!isPrime[i]) continue;
        for (int j = i*i; j <= MAX; j += i) isPrime[j] = false;
    }
    auto getTwoPrimes = [&isPrime](int x) {
        for (int i = 2; i < x; ++i) {
            if (isPrime[i] && isPrime[x-i]) {
                return make_tuple(i, x-i);
            }
        }
        return make_tuple(0, 0);
    };
    int n;
    cin >> n;
    if (n < 8) {
        cout << -1;
        return 0;
    }
    if (~n & 1) {
        auto [a, b] = getTwoPrimes(n-4);
        cout << 2 << ' ' << 2 << ' ' << a << ' ' << b;
    } else {
        auto [a, b] = getTwoPrimes(n-5);
        cout << 2 << ' ' << 3 << ' ' << a << ' ' << b;
    }
}