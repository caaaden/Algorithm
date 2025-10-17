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
#define endl '\n'

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
constexpr int dx2[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
constexpr int dy2[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
constexpr int bit = 9;
const long long MOD = 1e9 + 7;
const long long MOD2 = 1e9 + 9;
const int MAX = 1e9;

int main(){
    fastio;

    int n; cin >> n;
    string s; cin >> s;
    vector<vector<int>> dp(n, vector<int>(n));
    // 0...n-1
    // dp[i][i] = 1
    // dp[i][i+1] : s[i] == s[i+1] : 2 else 0
    for (int i = 0; i < n; ++i) {
        dp[i][i] = 1;
    }
    for (int i = 0; i < n-1; ++i) {
        if (s[i] == s[i+1]) dp[i][i+1] = 2;
        else dp[i][i+1] = 1;
    }
    for (int i = 2; i < n; ++i) {
        // i : offset
        // j, j+i
        // j+i < n
        for (int j = 0; j < n-i; ++j) {
            // dp[j][j+i]
            int a = j;
            int b = j+i;
            if (s[a] == s[b]) dp[a][b] = dp[a+1][b-1] + 2;
            else dp[a][b] = max(dp[a][b-1], dp[a+1][b]);
        }
    }
    // dp[0][n-1]
    cout << n - dp[0][n-1];
}