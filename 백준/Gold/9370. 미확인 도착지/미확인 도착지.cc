#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using pii = pair<int, int>;

const int MAX = 1e9;
int main() {
    fastio;

    int T;
    cin >> T;
    while (T--) {
        int n, m, t;
        cin >> n >> m >> t;
        int s, g, h;
        cin >> s >> g >> h;
        vector<vector<pii>> graph(n+1);
        int gh;
        for (int i = 0; i < m; ++i) {
            int a, b, d;
            cin >> a >> b >> d;
            if (a == g && b == h || a == h && b == g) gh = d;
            graph[a].push_back({b, d});
            graph[b].push_back({a, d});
        }
        vector<int> dest(t);
        for (auto& e : dest) cin >> e;
        auto dijkstra = [&](int start) {
            vector<int> dist(n+1, MAX);
            priority_queue<pii, vector<pii>, greater<pii>> pq;
            dist[start] = 0;
            pq.push({0, start});
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
            return dist;
        };
        vector<int> dist1 = dijkstra(s);
        vector<int> dist2 = dijkstra(g);
        vector<int> dist3 = dijkstra(h);
        vector<int> ans;
        for (auto& e : dest) if (dist1[g] + gh + dist3[e] == dist1[e] || dist1[h] + gh + dist2[e] == dist1[e]) ans.push_back(e);
        sort(ans.begin(), ans.end());
        for (auto& e : ans) cout << e << ' ';
        cout << '\n';
    }
}