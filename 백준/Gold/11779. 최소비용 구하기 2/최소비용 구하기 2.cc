#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using pii = pair<int, int>;

const int MAX = 1e9;
int main() {
    fastio;

    int n, m;
    cin >> n >> m;
    vector<vector<pii>> graph(n+1);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }
    int s, e;
    cin >> s >> e;
    vector<int> parent(n+1);
    auto dijkstra = [&]() {
        vector<int> dist(n+1, MAX);
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        dist[s] = 0;
        pq.push({0, s});
        while (pq.size()) {
            int cost = pq.top().first;
            int now = pq.top().second;
            pq.pop();
            if (dist[now] < cost) continue;
            for (auto& [next, nowToNxt] : graph[now]) {
                int nextCost = cost + nowToNxt;
                if (nextCost < dist[next]) {
                    dist[next] = nextCost;
                    pq.push({nextCost, next});
                    parent[next] = now;
                }
            }
        }
        return dist[e];
    };
    int shortestDistance = dijkstra();
    int node = e;
    vector<int> path;
    while (node) {
        path.push_back(node);
        node = parent[node];
    }
    reverse(path.begin(), path.end());
    cout << shortestDistance << '\n';
    cout << path.size() << '\n';
    for (auto& v : path) cout << v << ' ';
}