#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main() {
    fastio;

    int n;
    cin >> n;
    vector<map<string, int>> graph(15005);
    int idx = 0;
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        int now = 0;
        for (int j = 0; j < k; ++j) {
            string node;
            cin >> node;
            if (!graph[now].count(node)) graph[now][node] = ++idx;
            now = graph[now][node];
        }
    }
    function<void(int, int)> dfs = [&](int now, int depth) {
        for (auto& [node, next] : graph[now]) {
            for (int i = 0; i < depth*2; ++i) cout << '-';
            cout << node << '\n';
            dfs(next, depth+1);
        }
    };
    dfs(0, 0);
}