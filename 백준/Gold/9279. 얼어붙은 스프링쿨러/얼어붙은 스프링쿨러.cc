#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using pii = pair<int, int>;

int main() {
    fastio;

    int n, c;
    while (cin >> n >> c) {
        vector<vector<pii>> graph(n+1);
        for (int i = 0; i < n-1; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }
        vector<int> vis(n+1);
        function<int(int, int)> search = [&](int now, int cost) {
            if (now != c && graph[now].size() == 1) return cost;
            vis[now] = 1;
            int sum = 0;
            for (auto& [next, nextCost] : graph[now]) {
                if (vis[next]) continue;
                sum += search(next, nextCost);
            }
            return min(cost, sum);
        };
        cout << search(c, INT_MAX) << '\n';
    }
}