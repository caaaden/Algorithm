#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using pii = pair<int, int>;

int n, m;
vector<vector<pii>> graph;
vector<int> path;
const int MAX = 1e9;
int dijkstra(pii checkpoint) {
    // 1 -> n 최소 비용 return
    // u -> v or v -> u로 가는 경우 제외
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
    // dijkstra() : 1 -> n까지 가는 최소 비용을 return
    // graph, n
    int sp = dijkstra({-1, -1}); // 검문소가 없을 때 최단거리
    set<pii> st;
    int x = n;
    while (x > 1) {
        st.insert({x, path[x]});
        st.insert({path[x], x});
        x = path[x];
    }
//    for (auto& [a, b] : st) cout << a << ' ' << b << '\n';
    // 검문소가 최단거리를 이루는 경로에 포함된 엣지 중 하나가 아니면 continue
    // 엣지를 set으로 관리


    int delayed = 0;
    for (int i = 0; i < m; ++i) {
        // st.count(edges[i]) -> 검문소가 최단 경로에 포함되므로 다익스트라 진행
        // 포함되지 않을 경우 continue;
        if (!st.count(edges[i])) continue;
        int dist = dijkstra(edges[i]);
        if (dist == 1e9) {
            delayed = -1;
            break;
        }
        delayed = max(delayed, dist-sp);
    }
    cout << delayed;
}