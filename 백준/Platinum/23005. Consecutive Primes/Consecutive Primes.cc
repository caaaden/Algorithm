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
        for (int i = 2; i*i <= x; ++i) {
            if (x % i == 0) return false;
        }
        return true;
    };
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        ll z;
        cin >> z;
        int sq = (int)sqrt(z)+1;
        vector<int> primes;
        for (int i = sq; primes.empty(); ++i) {
            if (isPrime(i)) primes.push_back(i); // edge check
        }
        // sq보다 작은 숫자를 탐색,
        for (int i = sq-1; primes.size() < 3; --i) {
            if (isPrime(i)) primes.push_back(i);
        }
        // primes[0] * primes[1] <= z이면 이를 return
        // else primes[1] * primes[2]를 return
        cout << "Case #" << t << ": ";
        if ((ll)primes[0] * primes[1] <= z) {
            cout << (ll)primes[0] * primes[1] << '\n';
        } else {
            cout << (ll)primes[1] * primes[2] << '\n';
        }
    }
}