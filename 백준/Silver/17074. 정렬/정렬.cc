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

    int n; cin >> n;
    vector<int> v(n+2);
    v[0] = -1e9, v[n+1] = 1e9;
    for (int i = 1; i <= n; ++i) cin >> v[i];
    vector<int> isPrefixSorted(n+1);
    vector<int> isSuffixSorted(n+2);
    isPrefixSorted[0] = 1;
    isSuffixSorted[n+1] = 1;
    for (int i = 1; i <= n; ++i) {
        isPrefixSorted[i] = v[i-1] <= v[i];
        if (!isPrefixSorted[i]) break;
    }
    for (int i = n; i >= 1; --i) {
        isSuffixSorted[i] = v[i] <= v[i+1];
        if (!isSuffixSorted[i]) break;
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += isPrefixSorted[i-1] && isSuffixSorted[i+1] && v[i-1] <= v[i+1];
    }
    cout << ans;
}