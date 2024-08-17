#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
using pli = pair<i64, int>;

const i64 MAX = 1e16;
int main() {
    fastio;

    int n, m, a, b;
    i64 c;
    cin >> n >> m >> a >> b >> c;
    vector<vector<pii>> graph(n+1);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    // 골목 최대 수금량 제한을 이분탐색으로 찾기

    // 골목 최대 수금량 제한을 가진 다익스트라
    auto dijkstra = [&](int mid) {
        // 간선의 가중치가 mid 초과이면 중단
        vector<i64> dist(n+1, MAX);
        priority_queue<pli, vector<pli>, greater<pli>> pq;
        dist[a] = 0;
        pq.push({0, a});
        while (pq.size()) {
            i64 cost = pq.top().first;
            int now = pq.top().second;
            pq.pop();
            if (dist[now] < cost) continue;
            for (auto& [next, nowToNxt] : graph[now]) {
                if (nowToNxt > mid) continue;
                i64 nextCost = cost + nowToNxt;
                if (nextCost > c) continue;
                if (nextCost < dist[next]) {
                    dist[next] = nextCost;
                    pq.push({nextCost, next});
                }
            }
        }
        return dist[b] == MAX ? false : true;
    };
    int lo = 0, hi = 1e9;
    while (lo + 1 < hi) {
        // FF...FT...TT
        // 가장 작은 T
        int mid = (lo + hi) / 2;
        if (dijkstra(mid)) hi = mid;
        else lo = mid;
    }
    cout << (hi == 1e9 ? -1 : hi);
}