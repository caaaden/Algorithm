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

    int n; cin >> n;
    vector<int> t(n<<1);
    for (int i = n; i < (n<<1); ++i) {
        cin >> t[i];
    }
    auto build = [&]() {
        for (int i = n-1; i; --i) {
            t[i] = t[i<<1] + t[i<<1|1];
        }
    };
    auto modify = [&](int p, int diff) {
        for (t[p += n] += diff; p > 1; p >>= 1) {
            t[p>>1] = t[p] + t[p^1];
        }
    };
    auto query = [&](int l, int r) {
        int ret = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l&1) {
                ret += t[l];
                l++;
            }
            if (r&1) {
                r--;
                ret += t[r];
            }
        }
        return ret;
    };
    build();
    int m; cin >> m;
    while (m--) {
        int q; cin >> q;
        if (q == 1) {
            int i, diff;
            cin >> i >> diff;
            modify(i-1, diff);
        } else {
            int i; cin >> i;
            int lo = 0, hi = n+1;
            while (lo+1 < hi) {
                int mid = (lo+hi) / 2;
                if (i <= query(0, mid-1)) hi = mid;
                else lo = mid;
            }
            cout << lo << '\n';
        }
    }
}