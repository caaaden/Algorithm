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

    int T; cin >> T;
    while (T--) {
        int n, m; cin >> n >> m;
        vector<pii> t(n<<1);

        auto build = [&]() {
            for (int i = n; i < (n<<1); ++i) {
                t[i] = {i-n, i-n};
            }
            for (int i = n-1; i; --i) {
                t[i].X = min(t[i<<1].X, t[i<<1|1].X);
                t[i].Y = max(t[i<<1].Y, t[i<<1|1].Y);
            }
        };

        auto modify = [&](int a, int b) {
            int aIdx = a + n;
            int bIdx = b + n;
            pii tmpA = t[aIdx];
            pii tmpB = t[bIdx];
            for (t[aIdx] = tmpB; aIdx > 1; aIdx >>= 1) {
                t[aIdx>>1].X = min(t[aIdx].X, t[aIdx^1].X);
                t[aIdx>>1].Y = max(t[aIdx].Y, t[aIdx^1].Y);
            }
            for (t[bIdx] = tmpA; bIdx > 1; bIdx >>= 1) {
                t[bIdx>>1].X = min(t[bIdx].X, t[bIdx^1].X);
                t[bIdx>>1].Y = max(t[bIdx].Y, t[bIdx^1].Y);
            }
        };

        auto query = [&](int l, int r) {
            int mn = INT_MAX, mx = INT_MIN;
            int tl = l, tr = r;
            for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
                if (l&1) {
                    mn = min(mn, t[l].X);
                    mx = max(mx, t[l].Y);
                    l++;
                }
                if (r&1) {
                    r--;
                    mn = min(mn, t[r].X);
                    mx = max(mx, t[r].Y);
                }
            }
            return mn == tl && mx == tr-1;
        };

        build();
        while (m--) {
            int Q; cin >> Q;
            if (Q == 0) {
                int a, b; cin >> a >> b;
                modify(a, b);
            } else {
                int a, b; cin >> a >> b;
                cout << (query(a, b+1) ? "YES" : "NO") << '\n';
            }
        }
    }
}