#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
using pii = pair<int, int>;

const int MAX = 1e9;
int main() {
    fastio;

    int n, m, a, b, c;
    cin >> n >> m >> a >> b >> c;
    vector<vector<pii>> graph(n+1);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    // 경로를 이루는 간선 가중치 중 최댓값, 경로 가중치 합
    auto dijkstra = [&]() {
        vector<pii> dist(n+1, {MAX, MAX});
        priority_queue<pii, vector<pii>, greater<pii>> pq; // 간선 가중치 중 최댓값, 노드
        dist[a] = {0, 0};
        pq.push({0, 1});
        while (pq.size()) {
            int cost = pq.top().first; // 경로 가중치 중 최댓값
            int now = pq.top().second;
            pq.pop();
            if (dist[now].first < cost) continue;
            for (auto& [next, nowToNxt] : graph[now]) {
                int nextCost = max(cost, nowToNxt);
                int nextCost2 = dist[now].second + nowToNxt;
                if (nextCost < dist[next].first && nextCost2 <= c) {
                    dist[next].first = nextCost;
                    dist[next].second = nextCost2;
                    pq.push({nextCost, next});
                }
            }
        }
        return dist[b].first;
    };
    int ans = dijkstra();
    cout << (ans == MAX ? -1 : ans);
}