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
//using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

constexpr int dx[4] = {1, -1, 0, 0};
constexpr int dy[4] = {0, 0, 1, -1};
constexpr int bit = 9;
const long long MOD = 1e9 + 7;
const int MAX = 1e9;

int main(){
    fastio;

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<pii> points(n);
        vector<int> compressed;
        compressed.reserve(n);
        for (auto& [a, b] : points) {
            cin >> a >> b;
            compressed.push_back(b);
        }
        sort(all(compressed));
        compressed.erase(unique(all(compressed)), compressed.end());
        sort(all(points), [](const pii& a, const pii& b) {
            if (a.X == b.X) return a.Y > b.Y;
            return a.X < b.X;
        });
        ordered_multiset<int> ms;

        auto comp = [&compressed](int x) {
            return lower_bound(all(compressed), x) - compressed.begin();
        };

        for (auto& [a, b] : points) {
            ms.insert(comp(b));
        }
        ll ans = -n;
        for (auto& [a, b] : points) {
            int cnt = ms.order_of_key(comp(b)+1);
            ans += cnt;
            ms.erase(ms.find_by_order(ms.order_of_key(comp(b))));
        }
        cout << ans << '\n';
    }
}