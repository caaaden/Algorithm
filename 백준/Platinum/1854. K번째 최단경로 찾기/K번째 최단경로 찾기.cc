#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using pii = pair<int, int>;

int n, m, k;
vector<vector<pii>> graph;
const int MAX = 1e9;
void dijkstra() {
    // 1에서 모든 정점까지 k번째 최단거리 구하기.
    // dist[i] = {i로 가는 최단거리, k개의 최단거리를 담은 max heap}
    // max heap의 top은 k번째 최단거리
    //
    vector<priority_queue<int>> dist(n+1);
    for (int i = 1; i <= n; ++i) {
        dist[i].push(MAX);
    }
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    if (k == 1) dist[1].pop();
    dist[1].push(0);
    pq.push({0, 1});
    while (pq.size()) {
        int cost = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if (dist[now].top() < cost) continue;
        for (int i = 0; i < graph[now].size(); ++i) {
            int next = graph[now][i].first;
            int nextCost = cost + graph[now][i].second;
            if (dist[next].size() < k) {
                dist[next].push(nextCost);
                pq.push({nextCost, next});
            } else {
                // dist[next].size() == k
                if (dist[next].top() > nextCost) {
                    dist[next].pop();
                    dist[next].push(nextCost);
                    pq.push({nextCost, next});
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (dist[i].top() == MAX) cout << -1 << '\n';
        else cout << dist[i].top() << '\n';
    }
}

int main() {
    fastio;

    cin >> n >> m >> k;
    graph.resize(n+1);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }
    dijkstra();
}