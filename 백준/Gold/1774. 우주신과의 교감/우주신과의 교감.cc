#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
using pii = pair<int, int>;

struct Edge {
    int u, v;
    double w;
};

int main() {
    fastio;

    // 서로 다른 점 사이의 모든 거리를 구한다.
    // 간선에 추가한다.
    // mst를 이루는 간선에 이미 연결된 간선을 포함시킨다.
    // 나머지 간선들을 모두 연결한다.
    // 나머지 간선들을 모두 연결하는 데 드는 비용을 저장한다.
    // 출력한다.
    int n, m;
    cin >> n >> m;
    vector<pii> pos(n);
    for (auto& [a, b] : pos) cin >> a >> b;
    // 간선의 가중치가 floating point
    vector<Edge> edges;
    for (int i = 0; i < n-1; ++i) {
        for (int j = i+1; j < n; ++j) {
            int xDiff = pos[i].first - pos[j].first;
            int yDiff = pos[i].second - pos[j].second;
            double dist = sqrt(pow(xDiff, 2) + pow(yDiff, 2));
            edges.push_back({i+1, j+1, dist});
        }
    }
    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.w < b.w;
    });
    // find, merge
    // find = root를 return
    // parent(n+1);
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
        cnt++; // 연결된 간선의 개수
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
        // edges[i].u, v, w
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