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

    vector<bool> isPrime(200001, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i*i <= 200000; ++i) {
        if (!isPrime[i]) continue;
        for (int j = i*i; j <= 200000; j += i) isPrime[j] = false;
    }
    int n, a, b;
    cin >> n >> a >> b;
    vector<vector<int>> board(2, vector<int>(n));
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> board[i][j];
        }
    }
    auto score = [&](int x, int y) {
        return isPrime[x+y] ? a : b;
    };
    vector<int> dp(n+1);
    dp[0] = 0;
    dp[1] = score(board[0][0], board[1][0]);
    for (int i = 2; i <= n; ++i) {
        int s1 = dp[i-1] + score(board[0][i-1], board[1][i-1]);
        int s2 = dp[i-2] + score(board[0][i-2], board[0][i-1]) + score(board[1][i-2], board[1][i-1]);
        dp[i] = max(s1, s2);
    }
    cout << dp[n];
}