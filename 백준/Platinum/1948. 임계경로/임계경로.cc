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
        if (dist[now] == INT_MIN) continue;
        for (auto& [next, weight] : graph[now]) {
            if (dist[next] > dist[now] + weight) continue;
            if (dist[next] < dist[now] + weight) {
                dist[next] = dist[now] + weight;
                prev[next].clear();
            }
            prev[next].push_back(now);
        }
    }
    int cnt = 0;
    vector<int> vis(n+1);
    vis[e] = 1;
    Q.push(e);
    while (Q.size()) {
        int now = Q.front();
        Q.pop();
        for (auto& p : prev[now]) {
            cnt++;
            if (vis[p]) continue;
            vis[p] = 1;
            Q.push(p);
        }
    }
    cout << dist[e] << '\n' << cnt;
}