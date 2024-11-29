#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0);
#define all(v) v.begin(), v.end()
#define X first
#define Y second
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using piii = pair<int, pii>;

struct pair_hash {
    std::size_t operator()(const pii& p) const {
        auto hash1 = std::hash<int>{}(p.X);
        auto hash2 = std::hash<int>{}(p.Y);
        return hash1 ^ (hash2 << 1);
    }
};

int main() {
    fastio;

    int n, m;
    cin >> n >> m;
    vector<vector<pii>> graph(n+1);
    vector<int> indegree(n+1);
    vector<int> order;
    order.reserve(n);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        indegree[b]++;
    }
    int s, e;
    cin >> s >> e;
    queue<int> Q;
    Q.push(s);
    while (Q.size()) {
        int now = Q.front();
        Q.pop();
        order.push_back(now);
        for (auto& [next, weight] : graph[now]) {
            indegree[next]--;
            if (!indegree[next]) Q.push(next);
        }
    }
    vector<int> dist(n+1, INT_MIN);
    dist[s] = 0;
    vector<vector<int>> prev(n+1);
    for (auto& now : order) {
        if (dist[now] != INT_MIN) {
            for (auto& [next, weight] : graph[now]) {
                if (dist[next] < dist[now] + weight) {
                    dist[next] = dist[now] + weight;
                    prev[next].clear();
                    prev[next].push_back(now);
                } else if (dist[next] == dist[now] + weight) {
                    prev[next].push_back(now);
                }
            }
        }
    }
    // 정점에 대한 방문 표시, 간선의 개수는 ++
    int cnt = 0;
    vector<int> vis(n+1);
    queue<int> Q2;
    Q2.push(e);
    vis[e] = 1;
    while (Q2.size()) {
        int now = Q2.front();
        Q2.pop();
        for (auto& p : prev[now]) {
            cnt++;
            if (vis[p]) continue;
            vis[p] = 1;
            Q2.push(p);
        }
    }
    cout << dist[e] << '\n' << cnt;
}