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
        function<int(int)> search = [&](int now) {
            vis[now] = 1;
            int sum = 0;
            for (auto& [next, nextCost] : graph[now]) {
                if (vis[next]) continue;
                sum += min(search(next), nextCost);
            }
            return sum ? sum : INT_MAX;
        };
        cout << search(c) << '\n';
    }
}