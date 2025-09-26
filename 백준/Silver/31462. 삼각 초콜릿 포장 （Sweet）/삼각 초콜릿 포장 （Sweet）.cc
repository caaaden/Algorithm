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

    int n; cin >> n;
    vector<vector<char>> t(n, vector<char>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            cin >> t[i][j];
        }
    }
    vector<vector<int>> check(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (check[i][j]) continue;
            if (i == n-1) {
                cout << 0;
                return 0;
            }
            if (t[i][j] == 'R' && t[i+1][j] == 'R' && t[i+1][j+1] == 'R' && !check[i+1][j] && !check[i+1][j+1]) {
                check[i][j] = 1;
                check[i+1][j] = 1;
                check[i+1][j+1] = 1;
            } else if (t[i][j] == 'B' && t[i][j+1] == 'B' && t[i+1][j+1] == 'B' && !check[i][j+1] && !check[i+1][j+1]) {
                check[i][j] = 1;
                check[i][j+1] = 1;
                check[i+1][j+1] = 1;
            } else {
                cout << 0;
                return 0;
            }
        }
    }
    cout << 1;
}