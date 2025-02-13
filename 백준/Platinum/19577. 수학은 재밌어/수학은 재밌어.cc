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

    auto getPrimeFactors = [](int x) {
        map<int, int> factors;
        for (int i = 2; i*i <= x; ++i) {
            while (x % i == 0) {
                factors[i]++;
                x /= i;
            }
        }
        if (x > 1) factors[x]++;
        return factors;
    };
    auto power = [](int a, int b) {
        int ret = 1;
        for (int i = 0; i < b; ++i) ret *= a;
        return ret;
    };
    auto eulerPhi = [&getPrimeFactors, &power](int x) {
        map<int, int> factors = getPrimeFactors(x);
        int ret = 1;
        for (auto& [a, b] : factors) ret *= power(a, b-1) * (a-1);
        return ret;
    };
    auto getDivisors = [](int x) {
        vector<int> partialDivisors;
        for (int i = 1; i*i <= x; ++i) {
            if (x % i == 0) {
                partialDivisors.push_back(x/i);
            }
        }
        reverse(all(partialDivisors));
        return partialDivisors;
    };
    int n;
    cin >> n;
    vector<int> divs = getDivisors(n);
    for (auto& div : divs) {
        // div * phi(div) = n이 되는지 확인
        if (div * eulerPhi(div) == n) {
            cout << div;
            return 0;
        }
    }
    cout << -1;
}