#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
using pii = pair<int, int>;

int main() {
    fastio;

    int n;
    cin >> n;
    vector<vector<int>> graph(n+1);
    for (int i = 2; i <= n; ++i) {
        int p;
        cin >> p;
        graph[p].push_back(i);
    }
    vector<int> v(n+1);
    for (int i = 1; i <= n; ++i) cin >> v[i];
    vector<pii> dp(n+1);
    function<pii(int)> solve = [&](int parent) -> pii {
        if (graph[parent].empty()) return {0, 0};
        int sum = 0;
        for (auto& child : graph[parent]) {
            dp[child] = solve(child);
            sum += dp[child].first;
        }
        int mmax = sum;
        for (auto& child : graph[parent]) mmax = max(mmax, sum - dp[child].first + dp[child].second + v[parent] * v[child]);
        return {mmax, sum};
    };
    cout << solve(1).first;
}