#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

#define fastio ios::sync_with_stdio(0), cin.tie(0)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define X first
#define Y second
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define pb push_back
#define endl '\n'

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using psi = pair<string, int>;
using piii = pair<int, pii>;
using piiii = pair<pii, pii>;

//template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T, typename Compare = less<T>>
using ordered_set = tree<T, null_type, Compare, rb_tree_tag, tree_order_statistics_node_update>;

constexpr int dx[4] = {1, -1, 0, 0};
constexpr int dy[4] = {0, 0, 1, -1};
constexpr int dx2[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
constexpr int dy2[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
constexpr int bit = 9;
const long long MOD = 1e9 + 7;
const long long MOD2 = 1e9 + 9;
const int MAX = 1e9;

int main() {
    fastio;

    int n, m, a, b;
    ll c;
    cin >> n >> m >> a >> b >> c;
    vector<vector<pii>> graph(n+1);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    auto dijkstra = [&](int mid) {
        vector<ll> dist(n+1, MAX);
        priority_queue<pli, vector<pli>, greater<pli>> pq;
        dist[a] = 0;
        pq.push({0, a});
        while (pq.size()) {
            ll cost = pq.top().first;
            int now = pq.top().second;
            pq.pop();
            if (dist[now] < cost) continue;
            for (auto& [next, nowToNxt] : graph[now]) {
                if (nowToNxt > mid) continue;
                ll nextCost = cost + nowToNxt;
                if (nextCost > c) continue;
                if (nextCost < dist[next]) {
                    dist[next] = nextCost;
                    pq.push({nextCost, next});
                }
            }
        }
        return dist[b] == MAX ? false : true;
    };
    int lo = 0, hi = 1e9+1;
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if (dijkstra(mid)) hi = mid;
        else lo = mid;
    }
    cout << (hi == 1e9+1 ? -1 : hi);
}