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

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

constexpr int dx[4] = {1, -1, 0, 0};
constexpr int dy[4] = {0, 0, 1, -1};
constexpr int bit = 9;
const long long MOD = 1e9 + 7;
const int MAX = 1e9;

int main(){
    fastio;

    int n, m; cin >> n >> m;
    vector<vector<int>> t(n<<1);
    for (int i = n; i < (n<<1); ++i) {
        int x; cin >> x;
        t[i].push_back(x);
    }

    auto build = [&]() {
        for (int i = n-1; i; --i) {
            t[i].resize(t[i<<1].size()+t[i<<1|1].size());
            merge(all(t[i<<1]), all(t[i<<1|1]), t[i].begin());
        }
    };

    auto query = [&](int l, int r, int k) {
        
        auto check = [&](int x) {
            int idx = 0;
            for (int tmpL = n+l, tmpR = n+r; tmpL < tmpR; tmpL >>= 1, tmpR >>= 1) {
                if (tmpL&1) {
                    idx += lower_bound(all(t[tmpL]), x) - t[tmpL].begin();
                    tmpL++;
                }
                if (tmpR&1) {
                    tmpR--;
                    idx += lower_bound(all(t[tmpR]), x) - t[tmpR].begin();
                }
            }
            idx++;
            return idx <= k;
        };

        int lo = -1e9-1, hi = 1e9+1;
        while (lo+1 < hi) {
            int mid = (lo+hi) / 2;
            if (check(mid)) lo = mid;
            else hi = mid;
        }
        return lo;
    };

    build();
    while (m--) {
        int i, j, k;
        cin >> i >> j >> k;
        cout << query(i-1, j, k) << '\n';
    }
}