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

    int n, m, q;
    cin >> n >> m >> q;
    vector<int> idx[m+1];
    vector<ll> dp[m+1];
    vector<ll> pSum(n);
    for (int i = 0; i < n; ++i) {
        int p, a;
        cin >> p >> a;
        pSum[i] = (i ? pSum[i-1] : 0) + p;
        idx[a].push_back(i);
        dp[a].push_back((dp[a].size() ? dp[a].back() : 0) + p);
    }
    while (q--) {
        int t, l, r;
        cin >> t >> l >> r;
        --l, --r;
        ll a = pSum[r] - (l ? pSum[l-1] : 0);
        int s = lower_bound(all(idx[t]), l) - idx[t].begin();
        int e = upper_bound(all(idx[t]), r) - idx[t].begin() - 1;
        ll b = s <= e ? (dp[t][e] - (s ? dp[t][s-1] : 0)) : 0;
        b /= 2;
        cout << a - b << '\n';
    }
}