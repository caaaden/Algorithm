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

    auto factorizeWithNoDuplicate = [&](int x) {
        set<int> factors;
        for (int i = 2; i*i <= x; ++i) {
            while (x % i == 0) {
                x /= i;
                factors.insert(i);
            }
        }
        if (x > 1) factors.insert(x);
        return factors;
    };

    int n; cin >> n;
    vector<int> v(n);
    for (auto& e : v) cin >> e;
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(0, n-1);
    for (int i = 0; i < 10; ++i) {
        int idx = dist(mt);
        int num = v[idx];
        set<int> factors = factorizeWithNoDuplicate(num);
        for (auto& factor : factors) {
            vector<int> ans;
            for (auto& e : v) {
                if (e % factor == 0) {
                    ans.push_back(e);
                }
            }
            if (~n & 1) {
                if (ans.size() >= n/2) {
                    cout << "YES" << endl;
                    for (int j = 0; j < n/2; ++j) {
                        cout << ans[j] << ' ';
                    }
                    return 0;
                }
            } else {
                if (ans.size() >= n/2 + 1) {
                    cout << "YES" << endl;
                    for (int j = 0; j < n/2+1; ++j) {
                        cout << ans[j] << ' ';
                    }
                    return 0;
                }
            }
        }
    }
    cout << "NO";
}