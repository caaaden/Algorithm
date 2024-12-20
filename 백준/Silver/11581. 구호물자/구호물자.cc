#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0);
#define all(v) v.begin(), v.end()
#define X first
#define Y second
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using piii = pair<int, pii>;
using piiii = pair<pii, pii>;

int main() {
    fastio;

    int n;
    cin >> n;
//    if (n == 1) {
//        cout << "NO CYCLE";
//        return 0;
//    }
    vector<int> graph[n+1];
    for (int i = 1; i < n; ++i) {
        int edges;
        cin >> edges;
        for (int j = 0; j < edges; ++j) {
            int m;
            cin >> m;
            graph[i].push_back(m);
        }
    }
    vector<int> state(n+1);
    bool hasCycle = false;
    function<void(int)> dfs = [&](int now) {
        // 0 : 미방문
        // 1 : 방문중
        // 2 : 방문완료
        state[now] = 1;
        for (auto& next : graph[now]) {
            if (state[next]) {
                if (state[next] == 1) hasCycle = true;
                continue;
            }
            dfs(next);
        }
        state[now] = 2;
    };
    dfs(1);
    cout << (hasCycle ? "CYCLE" : "NO CYCLE");
}