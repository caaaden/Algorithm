#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0);
#define all(v) v.begin(), v.end()
#define X first
#define Y second
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using piii = pair<int, pii>;
using piiii = pair<pii, pii>;

int main() {
    fastio;
    
    vector<pii> v(8);
    for (auto& [a, b] : v) cin >> a >> b;
    vector<pii> graph[8];
    for (int i = 0; i < 7; ++i) {
        for (int j = i+1; j < 8; ++j) {
            int dist = abs(v[i].X - v[j].X) + abs(v[i].Y - v[j].Y);
            if (i >= 2 && ~i & 1 && i+1 == j) dist = min(dist, 10);
            graph[i].push_back({j, dist});
            graph[j].push_back({i, dist});
        }
    }
    auto dijkstra = [&]() {
        vector<ll> dist(8, LLONG_MAX);
        dist[0] = 0;
        priority_queue<pli, vector<pli>, greater<pli>> pq;
        pq.push({0, 0});
        while (pq.size()) {
            ll cost = pq.top().X;
            int now = pq.top().Y;
            pq.pop();
            if (dist[now] < cost) continue;
            for (auto& [next, nowToNxt] : graph[now]) {
                ll nextCost = cost + nowToNxt;
                if (nextCost < dist[next]) {
                    dist[next] = nextCost;
                    pq.push({nextCost, next});
                }
            }
        }
        return dist[1];
    };
    cout << dijkstra();
}