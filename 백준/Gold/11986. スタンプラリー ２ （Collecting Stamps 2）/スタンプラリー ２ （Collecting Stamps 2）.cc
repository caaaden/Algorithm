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

    int n; cin >> n;
    string s; cin >> s;
    vector<int> idx[3];
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'J') idx[0].push_back(i);
        else if (s[i] == 'O') idx[1].push_back(i);
        else idx[2].push_back(i);
    }
    ll caseO = 0;
    for (int i = 0; i <= n; ++i) {
        ll a = lower_bound(all(idx[0]), i) - idx[0].begin() - 1;
        int b = lower_bound(all(idx[2]), i) - idx[2].begin();
        caseO = max(caseO, (ll)((a + 1) * (idx[2].size() - b)));
    }
    ll base = 0;
    ll caseJ = 0, caseI = 0;
    for (auto& i : idx[1]) {
        ll a = lower_bound(all(idx[0]), i) - idx[0].begin() - 1;
        ll b = upper_bound(all(idx[2]), i) - idx[2].begin();
        caseJ += a + 1, caseI += idx[2].size() - b;
        base += (a + 1) * (idx[2].size() - b);
    }
    ll ans = base + max(caseO, max(caseJ, caseI));
    cout << ans;
}
