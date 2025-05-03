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

int main(){
    fastio;

    vector<ll> runNums;
    for (int i = 0; i < 17; ++i) {
        if (!i) {
            for (int j = 1; j < 10; ++j) runNums.push_back(j);
        } else {
            for (int j = 1; j < 10; ++j) {
                ll runNum = runNums[runNums.size()-9] * 10 + j;
                runNums.push_back(runNum);
            }
        }
    }
    reverse(all(runNums));
    int t;
    cin >> t;
    while (t--) {
        int n;
        ll k;
        cin >> n >> k;
        vector<ll> ans;
        for (auto& r : runNums) {
            if (r > k) continue;
            // r <= k
            k -= r;
            ans.push_back(r);
        }
        cout << ans.size() << '\n';
        for (auto& e : ans) cout << e << ' ';
        cout << '\n';
    }
}