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

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
        int sz = m + n;
        vector<int> t(sz<<1);
        vector<int> tIdx(n+1);
        for (int i = sz+m; i < (sz<<1); ++i) {
            t[i] = 1;
            tIdx[i-sz-m+1] = i;
        }
        for (int i = sz-1; i; --i) t[i] = t[i<<1] + t[i<<1|1];

        auto modify = [&](int idx, int diff) {
            for (t[idx] += diff; idx > 1; idx >>= 1) {
                t[idx>>1] = t[idx] + t[idx^1];
            }
        };

        auto query = [&](int l, int r) {
            int res = 0;
            for (; l < r; l >>= 1, r >>= 1) {
                if (l&1) res += t[l++];
                if (r&1) res += t[--r];
            }
            return res;
        };

        int idx = sz+m-1;
        while (m--) {
            int x; cin >> x;
            cout << query(sz, tIdx[x]) << ' ';
            modify(tIdx[x], -1);
            modify(idx, 1);
            tIdx[x] = idx;
            idx--;
        }
        cout << '\n';
    }

}