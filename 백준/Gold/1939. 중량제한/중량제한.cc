#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
using pii = pair<int, int>;

int n, m;
int s, e;
vector<vector<pii>> graph;
bool check(int x) {
    vector<int> vis(n+1);
    vis[s] = 1;
    queue<int> Q;
    Q.push(s);
    while (Q.size()) {
        int now = Q.front();
        Q.pop();
        if (now == e) return true;
        for (auto& [next, cost] : graph[now]) {
            if (cost < x) continue;
            if (vis[next]) continue;
            vis[next] = 1;
            Q.push(next);
        }
    }
    return false;
}

int main() {
    fastio;

    cin >> n >> m;
    graph.resize(n+1);
    map<pii, int> edges;
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        if (edges.count({a, b})) {
            if (edges[{a, b}] < c) {
                edges[{a, b}] = c;
            }
        } else {
            edges.insert({{a, b}, c});
        }
    }
    for (auto& [a, b] : edges) {
        graph[a.first].push_back({a.second, b});
        graph[a.second].push_back({a.first, b});
    }
    cin >> s >> e;
    int lo = 1, hi = 1e9+1;
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) lo = mid;
        else hi = mid;
    }
    cout << lo;
}