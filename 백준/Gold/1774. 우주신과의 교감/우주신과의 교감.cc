#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
using pii = pair<int, int>;
using i64 = long long;

struct Edge {
    int u, v;
    double w;
};

int main() {
    fastio;
    
    int n, m;
    cin >> n >> m;
    vector<pii> pos(n);
    for (auto& [a, b] : pos) cin >> a >> b;
    vector<Edge> edges;
    for (int i = 0; i < n-1; ++i) {
        for (int j = i+1; j < n; ++j) {
            i64 xDiff = pos[i].first - pos[j].first;
            i64 yDiff = pos[i].second - pos[j].second;
            double dist = sqrt(xDiff*xDiff + yDiff*yDiff);
            edges.push_back({i+1, j+1, dist});
        }
    }
    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.w < b.w;
    });
    vector<int> parent(n+1);
    for (int i = 1; i <= n; ++i) parent[i] = i;
    function<int(int)> find = [&](int x) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    };
    int cnt = 0;
    auto merge = [&](int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return;
        cnt++;
        if (a > b) parent[a] = b;
        else parent[b] = a;
    };
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        merge(u, v);
    }
    double ans = 0;
    for (int i = 0; cnt < n-1; ++i) {
        int a = edges[i].u;
        int b = edges[i].v;
        double c = edges[i].w;
        if (find(a) == find(b)) continue;
        merge(a, b);
        ans += c;
    }
    cout << fixed << setprecision(2);
    cout << ans;
}