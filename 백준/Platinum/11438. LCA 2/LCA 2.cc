#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main() {
    fastio;
    
    int n;
    cin >> n;
    vector<int> graph[n+1];
    for (int i = 0, a, b; i < n-1; ++i) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int k = (int)floor(log2(n-1));
    vector<vector<int>> parent(n+1, vector<int>(k+1));
    vector<int> vis(n+1);
    vector<int> level(n+1);
    queue<int> Q;
    Q.push(1);
    vis[1] = 1;
    while (Q.size()) {
        int now = Q.front(); Q.pop();
        for (int i = 0; i < graph[now].size(); ++i) {
            int next = graph[now][i];
            if (vis[next]) continue;
            parent[next][0] = now;
            Q.push(next);
            vis[next] = 1;
            level[next] = level[now] + 1;
        }
    }
    for (int i = 0; i < k; ++i) {
        for (int j = 1; j <= n; ++j) {
            parent[j][i+1] = parent[parent[j][i]][i];
        }
    }
    int m;
    cin >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        if (level[a] > level[b]) {
            int diff = level[a] - level[b];
            for (int i = 0; i <= k; ++i) {
                if (diff & (1 << i)) {
                    a = parent[a][i];
                }
            }
        }
        if (level[a] < level[b]) {
            int diff = level[b] - level[a];
            for (int i = 0; i <= k; ++i) {
                if (diff & (1 << i)) {
                    b = parent[b][i];
                }
            }
        }
        
        if (a != b) {
            for (int i = k; i >= 0; --i) {
                if (parent[a][i] != 0 && parent[a][i] != parent[b][i]) {
                    a = parent[a][i];
                    b = parent[b][i];
                }
            }
            a = parent[a][0];    
        }
        cout << a << '\n';
    }
}