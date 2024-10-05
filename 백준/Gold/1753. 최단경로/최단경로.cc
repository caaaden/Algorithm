#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define pb push_back
#define X first
#define Y second
#define all(v) v.begin(), v.end()
using namespace __gnu_pbds;
using namespace std;
using pii = pair<int, int>;
using ll = long long;
typedef tree<int, null_type, greater_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main() {
    fastio;

    int v, e;
    cin >> v >> e;
    int k;
    cin >> k;
    vector<vector<pii>> graph(v+1);
    for (int i = 0; i < e; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }
    auto dijkstra = [&]() {
        vector<int> dist(v+1, 1e9);
        dist[k] = 0;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, k});
        while (pq.size()) {
            int cost = pq.top().X;
            int now = pq.top().Y;
            pq.pop();
            if (dist[now] < cost) continue;
            for (auto& [next, nowToNext] : graph[now]) {
                int nextCost = cost + nowToNext;
                if (dist[next] > nextCost) {
                    dist[next] = nextCost;
                    pq.push({nextCost, next});
                }
            }
        }
        return dist;
    };
    vector<int> ans = dijkstra();
    for (int i = 1; i <= v; ++i) {
        if (ans[i] == 1e9) cout << "INF" << '\n';
        else cout << ans[i] << '\n';
    }
}