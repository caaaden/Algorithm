#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastio;

    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n+1);
    int s;
    for (int i = 1; i <= n; ++i) {
        int p;
        cin >> p;
        if (p == -1) {
            s = i;
            continue;
        }
        graph[p].push_back(i);
    }
    vector<int> compliment(n+1);
    while (m--) {
        int num;
        int amount;
        cin >> num >> amount;
        compliment[num] += amount;
    }
    vector<int> ans(n+1);
    queue<int> Q;
    Q.push(s);
    while (Q.size()) {
        int now = Q.front();
        Q.pop();
        for (auto& next : graph[now]) {
            compliment[next] += compliment[now];
            Q.push(next);
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << compliment[i] << ' ';
    }
}