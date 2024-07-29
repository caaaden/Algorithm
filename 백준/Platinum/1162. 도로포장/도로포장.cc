#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using plii = pair<ll, pii>;

int n, m, k;
const ll MAX = 1e16;
vector<vector<pii>> graph;
ll dijkstra() {
    vector<vector<ll>> dist(n+1, vector<ll>(k+1, MAX));
    priority_queue<plii, vector<plii>, greater<plii>> pq;
    dist[1][k] = 0;
    pq.push({0, {k, 1}});
    while (pq.size()) {
        ll cost = pq.top().first;
        int paveLeft = pq.top().second.first;
        int now = pq.top().second.second;
        pq.pop();
        if (dist[now][paveLeft] < cost) continue;
        for (auto& e : graph[now]) {
            int next = e.first;
            if (paveLeft > 0) {
                if (cost < dist[next][paveLeft-1]) {
                    dist[next][paveLeft-1] = cost;
                    pq.push({cost, {paveLeft-1, next}});
                }
            }
            if (cost + e.second < dist[next][paveLeft]) {
                dist[next][paveLeft] = cost + e.second;
                pq.push({dist[next][paveLeft], {paveLeft, next}});
            }
        }
    }
    // dist[n][0...k] 중 최솟값
    ll ret = MAX;
    for (int i = 0; i <= k; ++i) ret = min(ret, dist[n][i]);
    return ret;
}

int main() {
    fastio;


    cin >> n >> m >> k;
    graph.resize(n+1);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    cout << dijkstra();
}