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
const int MOD = 1e9 + 7;
// const ll MOD = 1e9 + 7;

int main(){
    fastio;

    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (auto& e : v) cin >> e;
    vector<int> v2 = v;
    reverse(all(v2));
    vector<int> tails;
    vector<int> len(n), len2(n);
    for (int i = 0; i < n; ++i) {
        int idx = lower_bound(all(tails), v[i]) - tails.begin();
        if (tails.size() == idx) tails.push_back(v[i]);
        else tails[idx] = v[i];
        len[i] = idx+1;
    }
    tails.clear();
    for (int i = 0; i < n; ++i) {
        int idx = lower_bound(all(tails), v2[i], greater<int>()) - tails.begin();
        if (tails.size() == idx) tails.push_back(v2[i]);
        else tails[idx] = v2[i];
        len2[i] = idx+1;
    }
    reverse(all(len2));
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) ans[i] = len[i] + len2[i] - 1;
    while (q--) {
        int x;
        cin >> x;
        cout << ans[x-1] << '\n';
    }
}