#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0);
#define all(v) v.begin(), v.end()
#define X first
#define Y second
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using piii = pair<int, pii>;

int main() {
    fastio;

    int n;
    cin >> n;
    vector<pii> v(n);
    for (auto& [a, b] : v) cin >> a >> b;
    vector<vector<int>> dp(n, vector<int>(n));
    function<int(int, int)> solve = [&](int s, int e) {
        if (s == e) return 0;
        if (dp[s][e]) return dp[s][e];
        int ret = INT_MAX;
        for (int i = s; i < e; ++i) {
            ret = min(ret, solve(s, i) + solve(i+1, e) + v[s].X * v[i].Y * v[e].Y);
        }
        return dp[s][e] = ret;
    };
    cout << solve(0, n-1);
}