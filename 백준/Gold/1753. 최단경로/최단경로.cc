#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using piii = pair<pair<int, int>, int>;

int v, e;
const int MAX = 1e9;
vector<int> dijkstra(int s, vector<vector<pii>>& g) {
    vector<int> dist(v+1, MAX);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[s] = 0;
    pq.push({0, s});
    while (pq.size()) {
        int cost = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if (dist[now] < cost) continue;
        for (int i = 0; i < g[now].size(); ++i) {
            int next = g[now][i].first;
            int nextCost = cost + g[now][i].second;
            if (nextCost < dist[next]) {
                dist[next] = nextCost;
                pq.push({nextCost, next}); // 현재 next까지의 최단 거리, next 번호
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> v >> e;
    int s;
    cin >> s;
    vector<vector<pii>> graph(v+1);
    for (int i = 0; i < e; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }
    
    
    // vector<piii> tmp(e);
    // for (int i = 0; i < e; ++i) {
    //     cin >> tmp[i].first.first >> tmp[i].first.second >> tmp[i].second;
    // }
    // sort(tmp.begin(), tmp.end(), [](piii& a, piii& b){
    //     if (a.first.first == b.first.first) {
    //         if (a.first.second == b.first.second) {
    //             return a.second < b.second;
    //         } else {
    //             return a.first.second < b.first.second;
    //         }
    //     } else {
    //         return a.first.first < b.first.first;
    //     }
    // });
    // vector<piii> tmp2;
    // tmp2.push_back(tmp[0]);
    // for (int i = 1; i < tmp.size(); ++i) {
    //     if (tmp[i].first == tmp[i-1].first) continue;
    //     tmp2.push_back(tmp[i]);
    // }
    // for (int i = 0; i < tmp2.size(); ++i) {
    //     int a = tmp2[i].first.first;
    //     int b = tmp2[i].first.second;
    //     int c = tmp2[i].second;
    //     graph[a].push_back({b, c});
    // }
    vector<int> ans = dijkstra(s, graph);
    for (int i = 1; i < ans.size(); ++i) {
        if (ans[i] == MAX) {
            cout << "INF" << '\n';
        } else {
            cout << ans[i] << '\n';
        }
    }
}