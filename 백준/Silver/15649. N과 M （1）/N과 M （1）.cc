#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int n, m;
vector<int> check;
vector<int> seq;
void dfs(int k) {
    if (k == m) {
        for (auto& e : seq) cout << e << ' ';
        cout << '\n';
        return;
    }
    for (int i = 1; i <= n; ++i) {
        if (check[i]) continue;
        check[i] = 1;
        seq.push_back(i);
        dfs(k+1);
        seq.pop_back();
        check[i] = 0;
    }
}

int main() {
    fastio;

    cin >> n >> m;
    check.resize(n+1);
    seq.reserve(m);
    dfs(0);
}
