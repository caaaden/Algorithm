#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define all(v) v.begin(), v.end()
#define X first
#define Y second
using namespace std;
using pii = pair<int, int>;

int main() {
    fastio;

    int v, e;
    cin >> v >> e;
    int k;
    cin >> k;
    vector<vector<pii>> graph(v+1);
    for (int i = 0; i < e; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }
    auto dijkstra = [&]() {
        vector<int> dist(v+1, 1e9);
        dist[k] = 0;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, k});
        while (pq.size()) {
            int cost = pq.top().X;
            int now = pq.top().Y;
            pq.pop();
            if (dist[now] < cost) continue;
            for (auto& [next, nowToNext] : graph[now]) {
                int nextCost = cost + nowToNext;
                if (dist[next] > nextCost) {
                    dist[next] = nextCost;
                    pq.push({nextCost, next});
                }
            }
        }
        return dist;
    };
    vector<int> ans = dijkstra();
    for (int i = 1; i <= v; ++i) {
        if (ans[i] == 1e9) cout << "INF" << '\n';
        else cout << ans[i] << '\n';
    }
}