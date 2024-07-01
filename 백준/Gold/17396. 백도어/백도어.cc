#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pli = pair<long long, int>;

const ll MAX = 999999999999999;
int n, m;
vector<pii> graph[100000];
ll dijkstra() {
    vector<ll> dist(n, MAX);
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    
    dist[0] = 0;
    pq.push({0, 0});
    
    while (!pq.empty()) {
        ll cost = pq.top().first;
        int now = pq.top().second;
        if (now == n-1) return dist[n-1];
        pq.pop();
        if (dist[now] < cost) continue;
        for (int i = 0; i < graph[now].size(); ++i) {
            int next = graph[now][i].first;
            ll nextCost = cost + graph[now][i].second;
            if (nextCost < dist[next]) {
                dist[next] = nextCost;
                pq.push({nextCost, next});
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    vector<int> cannotMove(n);
    for (int i = 0; i < n; ++i) cin >> cannotMove[i]; // n-1번째 인덱스를 제외하고 cannotMove[i] == 1이면 그래프 연결 X
    cannotMove[n-1] = 0;
    for (int i = 0; i < m; ++i) {
        int a, b, t;
        cin >> a >> b >> t;
        if (cannotMove[a] || cannotMove[b]) continue;
        graph[a].push_back({b, t});
        graph[b].push_back({a, t});
    }
    cout << dijkstra();
}