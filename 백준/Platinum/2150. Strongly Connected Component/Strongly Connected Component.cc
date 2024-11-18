#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0);
#define all(v) v.begin(), v.end()
#define X first
#define Y second
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int v, e;
vector<vector<int>> graph;
vector<vector<int>> graphRev;
vector<int> timeVisited;
vector<pii> arr;
vector<int> vis;
vector<int> vis2;
vector<vector<int>> scc;
vector<int> c;
int cnt;
void dfs(int now) {
    vis[now] = 1;
    for (auto& next : graph[now]) {
        if (vis[next]) continue;
        dfs(next);
    }
    timeVisited[now] = ++cnt;
    arr.push_back({now, timeVisited[now]});
}

void dfs2(int now) {
    vis2[now] = 1;
    c.push_back(now);
    for (auto& next : graphRev[now]) {
        if (vis2[next]) continue;
        dfs2(next);
    }
}

int main() {
    fastio;

    cin >> v >> e;
    graph.resize(v+1);
    graphRev.resize(v+1);
    timeVisited.resize(v+1);
    arr.reserve(v);
    vis.resize(v+1);
    vis2.resize(v+1);
    for (int i = 0; i < e; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graphRev[b].push_back(a);
    }
    for (int i = 1; i <= v; ++i) {
        if (vis[i]) continue;
        dfs(i);
    }
    sort(all(arr), [](const pii& a, const pii& b) {
        return a.second > b.second;
    });
    for (auto& [a, b] : arr) {
        if (vis2[a]) continue;
        dfs2(a);
        sort(all(c));
        scc.push_back(c);
        c.clear();
    }
    sort(all(scc));
    cout << scc.size() << '\n';
    for (auto& c : scc) {
        for (auto& x : c) cout << x << ' ';
        cout << -1 << '\n';
    }
}