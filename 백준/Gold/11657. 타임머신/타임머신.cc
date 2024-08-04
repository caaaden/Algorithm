#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
using pii = pair<int, int>;
using i64 = long long;

const int MAX = 1e9;
int main() {
    fastio;

    int n, m;
    cin >> n >> m;
    vector<vector<pii>> graph(n+1);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }
    vector<i64> dist(n+1, MAX);
    dist[1] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (auto& [next, cost] : graph[j]) {
                i64 nextCost = dist[j] + cost;
                if (dist[j] != MAX && dist[next] > nextCost) {
                    dist[next] = nextCost;
                    if (i == n) {
                        cout << -1;
                        return 0;
                    }
                }
            }
        }
    }
    for (int i = 2; i <= n; ++i) cout << (dist[i] == MAX ? -1 : dist[i]) << '\n';
}