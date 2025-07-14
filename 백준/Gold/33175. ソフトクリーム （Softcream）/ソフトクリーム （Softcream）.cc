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

int main() {
    fastio;

    int x, y, z;
    int p;
    cin >> x >> y >> z >> p;
    vector<int> a(x), b(y), c(z);
    for (auto& val : a) cin >> val;
    for (auto& val : b) cin >> val;
    for (auto& val : c) cin >> val;
    int cMn = *min_element(all(c));
    int cMx = *max_element(all(c));
    sort(all(b));
    int ans = 0;
    for (ll aVal : a) {
        int t1 = p - aVal - cMn;
        int t2 = p - aVal - cMx;
        int targetB = (t1 + t2) / 2;
        auto it = lower_bound(all(b), targetB);
        int ms = -1;
        if (it != b.end()) {
            ll bCand = *it;
            ll score = max(abs(aVal + bCand + cMn - p), abs(aVal + bCand + cMx - p));
            ms = score;
        }
        if (it != b.begin()) {
            ll bCand = *prev(it);
            ll score = max(abs(aVal + bCand + cMn - p), abs(aVal + bCand + cMx - p));
            if (ms == -1 || score < ms) ms = score;
        }
        ans = max(ans, ms);
    }
    cout << ans;
}