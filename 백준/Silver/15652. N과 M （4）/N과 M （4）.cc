#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int n, m;
vector<int> v;
void dfs(int k, int x) {
    if (k == m) {
        for (auto& e : v) cout << e << ' ';
        cout << '\n';
        return;
    }
    for (int i = x; i <= n; ++i) {
        v.push_back(i);
        dfs(k+1, i);
        v.pop_back();
    }
}

int main() {
    fastio;

    cin >> n >> m;
    dfs(0, 1);
}