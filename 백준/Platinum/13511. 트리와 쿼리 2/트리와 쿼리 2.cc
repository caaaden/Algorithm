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
    vector<vector<pil>> p(n+1, vector<pil>(k+1));
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

    auto getLCA = [&](int a, int b) {
        // a, b의 LCA 구하기
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
        return a;
    };

    auto getCost = [&](int a, int b, int lca) {
        int diffA = depth[a] - depth[lca];
        int diffB = depth[b] - depth[lca];
        ll cost = 0;
        for (int i = 0; i <= k; ++i) {
            if (diffA & (1 << i)) {
                cost += p[a][i].Y;
                a = p[a][i].X;
            }
            if (diffB & (1 << i)) {
                cost += p[b][i].Y;
                b = p[b][i].X;
            }
        }
        return cost;
    };

    int m;
    cin >> m;
    while (m--) {
        int op;
        cin >> op;
        if (op == 1) {
            int a, b;
            cin >> a >> b;
            int lca = getLCA(a, b);
            cout << getCost(a, b, lca) << '\n';
        } else {
            int a, b, c;
            cin >> a >> b >> c;
            int lca = getLCA(a, b);
            int x = depth[a] - depth[lca];
            c--;
            if (x >= c+1) {
                for (int i = 0; i <= k; ++i) if (c & (1 << i)) a = p[a][i].X;
                cout << a << '\n';
            } else {
                int y = depth[b] - depth[lca];
                c = y + x - c;
                for (int i = 0; i <= k; ++i) if (c & (1 << i)) b = p[b][i].X;
                cout << b << '\n';
            }
        }

    }
}