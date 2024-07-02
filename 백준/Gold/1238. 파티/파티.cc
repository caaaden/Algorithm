#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
using pii = pair<int, int>;

int n, m, x;
vector<int> dijkstra(vector<vector<pii>>& graph) {
    vector<int> dist(n+1, INT_MAX);
    dist[x] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, x});
    while (pq.size()) {
        int cost = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if (dist[now] < cost) continue;
        for (int i = 0; i < graph[now].size(); ++i) {
            int next = graph[now][i].first;
            int nextCost = cost + graph[now][i].second;
            if (dist[next] < nextCost) continue;
            dist[next] = nextCost;
            pq.push({nextCost, next});
        }
    }
    return dist;
}

int main() {
    fastio;

    cin >> n >> m >> x;
    vector<vector<pii>> graph1(n+1), graph2(n+1);
    for (int i = 0, a, b, c; i < m; ++i) {
        cin >> a >> b >> c; // 단방향
        graph1[a].push_back({b, c}); // 정방향
        graph2[b].push_back({a, c}); // 역방향
    }
    vector<int> dist1 = dijkstra(graph1);
    vector<int> dist2 = dijkstra(graph2);
    int ans = INT_MIN;
    for (int i = 1; i <= n; ++i) {
        if (i == x) continue;
        ans = max(ans, dist1[i] + dist2[i]);
    }
    cout << ans;
}
