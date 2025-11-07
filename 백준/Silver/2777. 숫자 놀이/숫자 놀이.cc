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
#define pb push_back
#define endl '\n'

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

//template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T, typename Compare = less<T>>
using ordered_set = tree<T, null_type, Compare, rb_tree_tag, tree_order_statistics_node_update>;

constexpr int dx[4] = {1, -1, 0, 0};
constexpr int dy[4] = {0, 0, 1, -1};
constexpr int dx2[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
constexpr int dy2[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
constexpr int bit = 9;
const long long MOD = 1e9 + 7;
const long long MOD2 = 1e9 + 9;
const int MAX = 1e9;

int main() {
    fastio;

    auto factorize = [](int x) {
        vector<int> factors;
        for (int i = 2; i*i <= x; ++i) {
            while (x % i == 0) {
                x /= i;
                factors.push_back(i);
            }
        }
        if (x > 1) factors.push_back(x);
        return factors;
    };

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        if (n < 10) {
            cout << 1 << endl;
            continue;
        }
        vector<int> factors = factorize(n);
        if (factors.back() >= 11) {
            cout << -1 << endl;
            continue;
        }
        vector<int> cnt(8);
        for (auto& f : factors) cnt[f]++;
        int ans = 0;
        ans += cnt[2] ? ((cnt[2]-1)/3)+1 : 0;
        if (cnt[2] % 3 == 1) if (cnt[3]) cnt[3]--;
        ans += cnt[3] ? ((cnt[3]-1)/2)+1 : 0;
        ans += cnt[5] + cnt[7];
        cout << ans << endl;
    }
}