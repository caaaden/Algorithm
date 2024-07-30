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
        graph[b].push_back({a, c});
    }
    auto dijkstra = [&](int start, vector<int>& parent) {
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<int> dist(n+1, MAX);
        dist[start] = 0;
        pq.push({0, start});
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
    };
    for (int i = 1; i <= n; ++i) {
        vector<int> parent(n+1);
        dijkstra(i, parent);
        for (int j = 1; j <= n; ++j) {
            if (i == j) {
                cout << '-' << ' ';
            } else {
                int node = j;
                vector<int> path;
                while (node) {
                    path.push_back(node);
                    node = parent[node];
                }
                cout << path[path.size()-2] << ' ';
            }
        }
        cout << '\n';
    }
}