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
    auto dijkstra = [&]() {
        vector<int> dist(n+1, MAX);
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        dist[1] = 0;
        pq.push({0, 1});
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
                }
            }
        }
        return dist[n];
    };
    cout << dijkstra();
}