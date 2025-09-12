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
    vector<int> a, b;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        if (x <= 0) {
            b.push_back(-x);
        } else {
            a.push_back(x);
        }
    }
    sort(all(a));
    sort(all(b));
    vector<int> ans;
    for (int i = 0; i <= n; ++i) {
        int num = upper_bound(all(a), i) - a.begin();
        num += b.size() - (lower_bound(all(b), i) - b.begin());
        int numOfLies = n - num;
        if (numOfLies == i) ans.push_back(i);
    }
    cout << ans.size() << '\n';
    for (auto& e : ans) cout << e << ' ';
}