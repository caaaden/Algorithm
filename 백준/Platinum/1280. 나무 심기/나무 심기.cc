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

    int n = 200000;
    vector<pli> t(n<<1);
    int m; cin >> m;
    ll ans = 1;
    auto modify = [&](int p) {
        t[p+n].X += p;
        t[p+n].Y++;
        p += n;
        for (; p > 1; p >>= 1) {
            t[p>>1] = {t[p].X+t[p^1].X, t[p].Y+t[p^1].Y};
        }
    };
    auto query = [&](int l, int r) {
        ll sum = 0;
        int len = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l&1) {
                sum += t[l].X;
                len += t[l].Y;
                l++;
            }
            if (r&1) {
                r--;
                sum += t[r].X;
                len += t[r].Y;
            }
        }
        return make_pair(sum, len);
    };
    {
        int x; cin >> x;
        modify(x);
    }
    for (int i = 1; i < m; ++i) {
        int x; cin >> x;
        auto [sumA, lenA] = query(0, x);
        auto [sumB, lenB] = query(x+1, n);
        ans *= ((ll)x * (lenA - lenB) + (sumB - sumA)) % MOD;
        ans %= MOD;
        modify(x);
    }
    cout << ans;
}