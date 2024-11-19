#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0);
#define all(v) v.begin(), v.end()
#define X first
#define Y second
using namespace std;

int main() {
    fastio;

    int n;
    cin >> n;
    vector<vector<int>> graph(n+1);
    for (int i = 0; i < n-1; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<int> vis(n+1);
    vector<int> depth(n+1);
    vector<vector<int>> p(n+1, vector<int>(20));
    function<void(int, int)> dfs = [&](int now, int d) {
        vis[now] = 1;
        depth[now] = d;
        for (auto& next : graph[now]) {
            if (vis[next]) continue;
            p[next][0] = now;
            dfs(next, d+1);
        }
    };
    dfs(1, 0);
    for (int i = 1; i < 20; ++i) {
        for (int j = 1; j <= n; ++j) {
            p[j][i] = p[p[j][i-1]][i-1];
        }
    }
    int m;
    cin >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        if (depth[a] < depth[b]) swap(a, b);
        int diff = depth[a] - depth[b];
        for (int i = 0; i < 20; ++i) if (diff & (1 << i)) a = p[a][i];
        if (a != b) {
            for (int i = 19; i >= 0; --i) {
                if (p[a][i] && p[a][i] != p[b][i]) {
                    a = p[a][i];
                    b = p[b][i];
                }
            }
            a = p[a][0];
        }
        cout << a << '\n';
    }
}