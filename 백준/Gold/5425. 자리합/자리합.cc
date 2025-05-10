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

    auto powerInt = [](int base, int exp) {
        ll res = 1;
        for (int i = 0; i < exp; ++i) res *= base;
        return res;
    };

    vector<ll> p(16);
    for (int i = 1; i < 16; ++i) p[i] = 45 * powerInt(10, i-1) + p[i-1] * 10;

    function<ll(ll)> digitSumInRange = [&](ll x) {
        if (x < 10) {
            ll sum = 0;
            for (int i = 0; i < x; ++i) sum += i;
            return sum;
        }
        int sz = to_string(x).size();
        int firstDigit = x / powerInt(10, sz-1);
        ll ret = 0;
        for (int i = 0; i < firstDigit; ++i) ret += i;
        ret *= powerInt(10, sz-1);
        ret += firstDigit * p[sz-1];
        ll r = x % powerInt(10, sz-1);
        return ret + firstDigit * r + digitSumInRange(r);
    };

    int t;
    cin >> t;
    while (t--) {
        ll a, b;
        cin >> a >> b;
        cout << digitSumInRange(b+1) - digitSumInRange(a) << '\n';
    }
}