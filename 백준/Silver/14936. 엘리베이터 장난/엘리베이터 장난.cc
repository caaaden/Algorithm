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

//template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T, typename Compare = less<T>>
using ordered_set = tree<T, null_type, Compare, rb_tree_tag, tree_order_statistics_node_update>;

constexpr int dx[4] = {1, -1, 0, 0};
constexpr int dy[4] = {0, 0, 1, -1};
constexpr int bit = 9;
const long long MOD = 1e9 + 7;
const long long MOD2 = 1e9 + 9;
const int MAX = 1e9;

int main(){
    fastio;

    int n, m; cin >> n >> m;
    set<vector<bool>> st;
    for (int i = 0; i < (1 << 4); ++i) {
        vector<int> cost = {n, n/2, (n & 1 ? (n/2)+1 : n/2), ((n-1)/3)+1};
        int totalCost = 0;
        vector<int> selected(4);
        for (int j = 0; j < 4; ++j) {
            if (i & (1 << j)) {
                totalCost += cost[j];
                selected[j] = 1;
            }
        }
        if (totalCost > m) continue;
        vector<bool> buttons(n+1);
        if (selected[0]) {
            for (int j = 1; j <= n; ++j) {
                buttons[j] = !buttons[j];
            }
        }
        if (selected[1]) {
            for (int j = 2; j <= n; j += 2) {
                buttons[j] = !buttons[j];
            }
        }
        if (selected[2]) {
            for (int j = 1; j <= n; j += 2) {
                buttons[j] = !buttons[j];
            }
        }
        if (selected[3]) {
            for (int j = 1; j <= n; j += 3) {
                buttons[j] = !buttons[j];
            }
        }
        st.insert(buttons);
    }
    cout << st.size();
}