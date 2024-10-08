#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using pii = pair<int, int>;

int n, m;
vector<vector<pii>> graph;
vector<int> path;
const int MAX = 1e9;
int dijkstra(pii checkpoint) {
    vector<int> dist(n+1, MAX);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[1] = 0;
    pq.push({0, 1});
    while (pq.size()) {
        int cost = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if (dist[now] < cost) continue;
        for (int i = 0; i < graph[now].size(); ++i) {
            int next = graph[now][i].first;
            int nextCost = cost + graph[now][i].second;
            if (now == checkpoint.first && next == checkpoint.second) continue;
            if (now == checkpoint.second && next == checkpoint.first) continue;
            if (nextCost < dist[next]) {
                path[next] = now;
                dist[next] = nextCost;
                pq.push({nextCost, next});
            }
        }
    }
    return dist[n];
}

int main() {
    fastio;

    cin >> n >> m;
    graph.resize(n+1);
    path.resize(n+1);
    vector<pii> edges(m);
    for (int i = 0; i < m; ++i) {
        int a, b, t;
        cin >> a >> b >> t;
        edges[i] = {a, b};
        graph[a].push_back({b, t});
        graph[b].push_back({a, t});
    }
    int sp = dijkstra({-1, -1});
    vector<vector<int>> check(n+1, vector<int>(n+1));
    int x = n;
    while (x > 1) {
        check[x][path[x]] = 1;
        check[path[x]][x] = 1;
        x = path[x];
    }
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        if (!check[edges[i].first][edges[i].second]) continue;
        int dist = dijkstra(edges[i]);
        ans = max(ans, dist);
    }
    cout << ans;
}