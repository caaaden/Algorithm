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

    auto isPrime = [](int x) {
        // x가 소수인 지 확인
        for (int i = 2; i*i <= x; ++i) {
            if (x % i == 0) return false;
        }
        return true;
    };
    auto getTwoPrimes = [&isPrime](int x) {
        // x를 두 소수의 합으로 나타내기
        for (int i = 2; i < x; ++i) {
            // i가 소수인 지 확인,
            // i가 소수라면, x-i도 소수인 지 확인,
            // x-i도 소수라면 i, x-i를 return
            if (isPrime(i) && isPrime(x-i)) {
                return make_tuple(i, x-i);
            }
        }
        return make_tuple(0, 0);
    };
    int n, k;
    cin >> n >> k;
    if (k == 1) {
        if (isPrime(n)) cout << n;
        else cout << -1;
        return 0;
    }
    if (n < k*2) {
        cout << -1;
        return 0;
    }
    if (~n & 1) {
        auto [a, b] = getTwoPrimes(n-(k*2-4));
        for (int i = 0; i < k-2; ++i) cout << 2 << ' ';
        cout << a << ' ' << b;
    } else {
        if (k == 2) {
            auto [a, b] = getTwoPrimes(n);
            if (!a && !b) cout << -1;
            else cout << a << ' ' << b;
        } else {
            auto [a, b] = getTwoPrimes(n-(k*2-3));
            for (int i = 0; i < k-3; ++i) cout << 2 << ' ';
            cout << 3 << ' ' << a << ' ' << b;
        }
    }
}