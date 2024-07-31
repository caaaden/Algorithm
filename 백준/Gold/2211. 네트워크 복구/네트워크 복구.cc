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
        vector<int> dist(n+1, MAX);
        priority_queue<pii, vector<pii>, greater<pii>> pq;
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
    vector<int> parent(n+1);
    dijkstra(1, parent);
    set<pii> s;
    for (int j = 2; j <= n; ++j) {
        int node = j;
        vector<int> path;
        while (parent[node]) {
            if (node > parent[node]) s.insert({parent[node], node});
            else s.insert({node, parent[node]});
            node = parent[node];
        }
    }
    cout << s.size() << '\n';
    for (auto& [a, b] : s) cout << a << ' ' << b << '\n';
}