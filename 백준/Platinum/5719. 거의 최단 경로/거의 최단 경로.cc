#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using pii = pair<int, int>;

int n, m;
int s, d;
vector<vector<pii>> graph;
vector<vector<int>> path;
vector<vector<int>> check;
const int MAX = 1e9;
int dijkstra() {
    vector<int> dist(n, MAX);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[s] = 0;
    pq.push({0, s});
    while (pq.size()) {
        int cost = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if (dist[now] < cost) continue;
        for (auto& [next, nextCost] : graph[now]) {
            if (check[now][next]) continue;
            if (cost + nextCost < dist[next]) {
                path[next].clear();
                path[next].push_back(now);
                dist[next] = cost + nextCost; // s -> now, now -> next
                pq.push({dist[next], next});
            } else if (cost + nextCost == dist[next]) {
                path[next].push_back(now);
            }
        }
    }
    return dist[d];
}

int main() {
    fastio;

    while (true) {
        cin >> n >> m;
        if (!n && !m) break;
        graph.clear();
        graph.resize(n);
        path.clear();
        path.resize(n);
        check.clear();
        check.resize(n, vector<int>(n));
        vector<int> vis(n);
        cin >> s >> d;
        for (int i = 0; i < m; ++i) {
            int u, v, p;
            cin >> u >> v >> p;
            graph[u].push_back({v, p});
        }
        dijkstra();
        vis[d] = 1;
        queue<int> Q;
        Q.push(d);
        while (Q.size()) {
            int now = Q.front();
            Q.pop();
            if (now == s) continue;
            for (auto& next : path[now]) {
                check[next][now] = 1;
                if (vis[next]) continue;
                vis[next] = 1;
                Q.push(next);
            }
        }
        int ans = dijkstra();
        cout << (ans == MAX ? -1 : ans) << '\n';
    }
}