#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0);
#define all(v) v.begin(), v.end()
#define X first
#define Y second
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;

int main() {
    fastio;

    int n;
    cin >> n;
    int k = (int)floor(log2(n-1));
    vector<vector<pii>> graph(n+1);
    for (int i = 0; i < n-1; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    vector<int> vis(n+1);
    vector<int> depth(n+1);
    vector<vector<pii>> p(n+1, vector<pii>(k+1));
    function<void(int, int)> dfs = [&](int now, int d) {
        vis[now] = 1;
        depth[now] = d;
        for (auto& [next, cost] : graph[now]) {
            if (vis[next]) continue;
            p[next][0] = {now, cost};
            dfs(next, d+1);
        }
    };
    dfs(1, 0);
    for (int i = 1; i <= k; ++i) {
        for (int j = 1; j <= n; ++j) {
            int mid = p[j][i-1].X;
            p[j][i].X = p[mid][i-1].X;
            p[j][i].Y = p[mid][i-1].Y + p[j][i-1].Y;
        }
    }
    int m;
    cin >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        int aa = a, bb = b;
        if (depth[a] < depth[b]) swap(a, b);
        int diff = depth[a] - depth[b];
        for (int i = 0; i <= k; ++i) if (diff & (1 << i)) a = p[a][i].X;
        if (a != b) {
            for (int i = k; i >= 0; --i) {
                if (p[a][i].X && p[a][i].X != p[b][i].X) {
                    a = p[a][i].X;
                    b = p[b][i].X;
                }
            }
            a = p[a][0].X;
        }
        int diffA = depth[aa] - depth[a];
        int diffB = depth[bb] - depth[a];
        int cost = 0;
        for (int i = 0; i <= k; ++i) {
            if (diffA & (1 << i)) {
                cost += p[aa][i].Y;
                aa = p[aa][i].X;
            }
            if (diffB & (1 << i)) {
                cost += p[bb][i].Y;
                bb = p[bb][i].X;
            }
        }
        cout << cost << '\n';
    }
}