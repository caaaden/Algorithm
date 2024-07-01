#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int v, e, s;
const int MAX = 1e9;
vector<int> dijkstra(vector<vector<pii>>& g) {
    vector<int> dist(v+1, MAX);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[s] = 0;
    pq.push({0, s});
    while (pq.size()) {
        int cost = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if (dist[now] < cost) continue;
        for (int i = 0; i < g[now].size(); ++i) {
            int next = g[now][i].first;
            int nextCost = cost + g[now][i].second;
            if (nextCost < dist[next]) {
                dist[next] = nextCost;
                pq.push({nextCost, next});
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> v >> e;
    cin >> s;
    vector<vector<pii>> graph(v+1);
    for (int i = 0, a, b, c; i < e; ++i) {
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }
    vector<int> ans = dijkstra(graph);
    for (int i = 1; i < ans.size(); ++i) {
        if (ans[i] == MAX) cout << "INF" << '\n';
        else cout << ans[i] << '\n';
    }
}