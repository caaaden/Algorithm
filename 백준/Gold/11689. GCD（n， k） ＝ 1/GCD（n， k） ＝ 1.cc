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

    auto getPrimeFactors = [](ll x) {
        // vector<ll> factors;
        map<ll, int> factors;
        for (ll i = 2; i*i <= x; ++i) {
            while (x % i == 0) {
                // factors.push_back(i);
                factors[i]++;
                x /= i;
            }
        }
        if (x > 1) factors[x]++;
        return factors;
    };
    auto power = [](int a, int b) {
        ll ret = 1;
        for (int i = 0; i < b; ++i) ret *= a;
        return ret;
    };
    ll n;
    cin >> n;
    map<ll, int> factors = getPrimeFactors(n);
    // 2 2 2 3 3 5
    // 2 : 3
    // 3 : 2
    // 5 : 1
    // pi(p^a) = p^(a-1) (p - 1)
    ll ans = 1;
    for (auto& [a, b] : factors) {
        // a : 소수
        // b : 지수
        // a^b
        ans *= power(a, b-1) * (a - 1);
    }
    cout << ans;
}