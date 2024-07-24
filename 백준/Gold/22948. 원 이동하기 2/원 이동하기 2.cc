#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using pii = pair<int, int>;
using piii = pair<int, pii>;

int main() {
    fastio;

    int n;
    cin >> n;
    vector<piii> v(n);
    for (auto& e : v) {
        int k, x, r;
        cin >> k >> x >> r;
        e = {k, {x-r, x+r}};
    }
    sort(v.begin(), v.end(), [](const piii& a, const piii& b) {
        return a.second.first < b.second.first;
    });
    stack<piii> st;
    vector<vector<int>> graph(n+1);
    for (auto& e : v) {
        if (st.empty()) {
            graph[0].push_back(e.first);
            graph[e.first].push_back(0);
            st.push(e);
        } else {
            while (st.size() && st.top().second.second < e.second.second) st.pop();
            if (st.empty()) {
                graph[0].push_back(e.first);
                graph[e.first].push_back(0);
                st.push(e);
                continue;
            }
            graph[st.top().first].push_back(e.first);
            graph[e.first].push_back(st.top().first);
            st.push(e);
        }
    }
    int a, b;
    cin >> a >> b;
    // a -> b로 가는 경로 탐색
    // dfs
    vector<int> vis(n+1);
    vector<int> path;
    function<void(int)> dfs = [&](int now) {
        vis[now] = 1;
        path.push_back(now);
        if (now == b) {
            cout << path.size() << '\n';
            for (auto& e : path) cout << e << ' ';
            exit(0);
        }
        // now와 연결된 정점 중, 방문하지 않은 정점에 대해서,
        // graph[now]
        for (auto& e : graph[now]) {
            if (vis[e]) continue;
            dfs(e);
        }
        vis[now] = 0;
        path.pop_back();
    };
    dfs(a);
}