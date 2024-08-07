#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
using pii = pair<int, int>;

int main() {
    fastio;

    int n;
    cin >> n;
    vector<vector<int>> graph(n+1);
    for (int i = 0; i < n-1; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
//    vector<vector<int>> dp(n+1, vector<int>(2));
//    for (int i = 1; i <= n; ++i) dp[i][1] = 1;
    function<pii(int, int)> solve = [&](int now, int parent) -> pii {
        if (graph[now].size() == 1 && parent) return {0, 1};
        int a = 0, b = 1;
        for (auto& child : graph[now]) {
            if (child == parent) continue;
            pii tmp = solve(child, now);
            a += tmp.second;
            b += min(tmp.first, tmp.second);
        }
        return {a, b};
        // {now가 얼리어답터가 아닐 때, now가 얼리어답터일 때}
    };
    pii ans = solve(1, 0);
    cout << min(ans.first, ans.second);
}