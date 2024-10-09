#include <bits/stdc++.h>
using namespace std;

int parent[10001];

void init(int n) {
    for (int i = 1; i <= n; ++i) parent[i] = i;
}

int find(int a) {
    if (a == parent[a]) return a;
    return parent[a] = find(parent[a]);
}

void merge(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return;
    if (a > b) parent[a] = b;
    else parent[b] = a;
}

struct Edge {
    int u, v, w;
    bool operator<(const Edge& r) const {
        return w < r.w;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int v, e;
    cin >> v >> e;
    init(v);
    vector<Edge> edges(e);
    for (int i = 0; i < e; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[i] = {a, b, c};
    }
    sort(edges.begin(), edges.end()); // 간선 가중치에 대해 오름차순 정렬,
    int cnt = 0; // 간선의 개수,
    int idx = 0; // edges의 index
    int res = 0;
    while (cnt != v-1) {
        // 간선의 개수가 v-1개가 될 때까지 반복,
        int a = edges[idx].u;
        int b = edges[idx].v;
        int c = edges[idx].w;
        idx++;
        if (find(a) == find(b)) continue; // 같은 집합이면, 사이클,
        merge(a, b);
        res += c;
        cnt++;
    }
    cout << res;
}