#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
using pii = pair<int, int>;

int n, e;
vector<vector<pii>> graph;
vector<int> dijkstra(int s) {
    vector<int> dist(n+1, INT_MAX);
    dist[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, s});
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

    // 1 -> v1 -> v2 -> n
    // 1 -> v2 -> v1 -> n
    cin >> n >> e;
    graph.resize(n+1);
    for (int i = 0, a, b, c; i < e; ++i) {
        cin >> a >> b >> c;
        // 양방향
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    int v1, v2;
    cin >> v1 >> v2;
    if (e == 0) {
        cout << -1;
        return 0;
    }
    vector<int> dist1 = dijkstra(1);
    if (v1 == 1 || v2 == n) {
        cout << dist1[n];
        return 0;
    }
    vector<int> dist2 = dijkstra(v1);
    vector<int> dist3 = dijkstra(v2);
    bool flag1 = dist1[v1] == INT_MAX || dist2[v2] == INT_MAX || dist3[n] == INT_MAX; // 하나라도 경로가 존재하지 않으면 true
    bool flag2 = dist1[v2] == INT_MAX || dist3[v1] == INT_MAX || dist2[n] == INT_MAX;
    if (flag1 && flag2) {
        cout << -1;
    } else if (flag1) {
        cout << dist1[v2] + dist3[v1] + dist2[n];
    } else if (flag2) {
        cout << dist1[v1] + dist2[v2] + dist3[n];
    } else {
        cout << min(dist1[v1] + dist2[v2] + dist3[n], dist1[v2] + dist3[v1] + dist2[n]);
    }
}
