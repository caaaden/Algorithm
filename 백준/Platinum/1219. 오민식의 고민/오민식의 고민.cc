#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
using pii = pair<int, int>;
using i64 = long long;

struct Edge {
    int u, v, w;
};

const int MAX = 1e9;
int main() {
    fastio;

    int n, s, e, m;
    cin >> n >> s >> e >> m;
    vector<Edge> edges(m);
    for (auto& edge : edges) cin >> edge.u >> edge.v >> edge.w;
    vector<int> nodeWeights(n);
    for (auto& w : nodeWeights) cin >> w;
    vector<vector<pii>> graph(n+1);
    for (auto& edge : edges) graph[edge.u].push_back({edge.v, edge.w - nodeWeights[edge.v]});
    vector<i64> dist(n, MAX);
    dist[s] = 0;
    for (int i = 0; i < n; ++i) {
        if (i == n-1) {
            if (dist[e] == MAX) {
                cout << "gg";
                return 0;
            }
        }
        for (int j = 0; j < n; ++j) {
            for (auto& [next, cost] : graph[j]) {
                i64 nextCost = dist[j] + cost;
                if (dist[j] != MAX && dist[next] > nextCost) {
                    dist[next] = nextCost;
                    if (i == n-1) {
                        // 음의 사이클이 존재, 그러나 시작지점에서 도착지점으로 가는 최단거리는 존재할 수 있음
                        // 사이클의 한 점에서 도착지점까지 갈 수 있는가? BFS or DFS로 판단
                        // next -> e bfs
                        // graph, 시작점, 끝점
                        auto bfs = [&graph, &n, &e](int start) {
                            vector<int> vis(n);
                            vis[start] = 1;
                            queue<int> Q;
                            Q.push(start);
                            while (Q.size()) {
                                int now = Q.front();
                                Q.pop();
                                for (auto& elem : graph[now]) {
                                    int next = elem.first;
                                    if (vis[next]) continue;
                                    vis[next] = 1;
                                    Q.push(next);
                                }
                            }
                            return (bool)vis[e];
                        };
                        if (bfs(next)) {
                            cout << "Gee";
                            return 0;
                        }
                    }
                }
            }
        }
    }
    cout << -(dist[e] - nodeWeights[s]);
}