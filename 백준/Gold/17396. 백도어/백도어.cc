#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
using pli = pair<i64, int>;

const i64 MAX = LLONG_MAX;
int n, m;
vector<vector<pii>> graph;
i64 dijkstra() {
    vector<i64> dist(n, MAX);
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    dist[0] = 0;
    pq.push({0, 0});
    while (pq.size()) {
        i64 cost = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if (dist[now] < cost) continue;
        for (int i = 0; i < graph[now].size(); ++i) {
            int next = graph[now][i].first;
            i64 nextCost = cost + graph[now][i].second;
            if (nextCost < dist[next]) {
                dist[next] = nextCost;
                pq.push({nextCost, next});
            }
        }
    }
    return dist[n-1] == MAX ? -1 : dist[n-1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    graph.resize(n+1);
    vector<int> isSighted(n);
    for (int i = 0; i < n; ++i) cin >> isSighted[i];
    isSighted[n-1] = 0;
    for (int i = 0; i < m; ++i) {
        int a, b, t;
        cin >> a >> b >> t;
        if (isSighted[a] || isSighted[b]) continue;
        graph[a].push_back({b, t});
        graph[b].push_back({a, t});
    }
    cout << dijkstra();
}