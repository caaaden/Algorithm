#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int n;
vector<int> durability;
vector<int> weights;
int ans = 0;

void dfs(int k) {
    if (k == n) {
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (durability[i] <= 0) cnt++;
        }
        ans = max(ans, cnt);
        return;
    }
    bool flag = true;
    for (int i = 0; i < n; ++i) {
        if (i == k) continue;
        if (durability[i] <= 0) continue;
        flag = false;
    }
    if (flag || durability[k] <= 0) dfs(k+1);
    else {
        for (int i = 0; i < n; ++i) {
            if (i == k) continue;
            if (durability[i] <= 0) continue;
            durability[k] -= weights[i];
            durability[i] -= weights[k];
            dfs(k+1);
            durability[k] += weights[i];
            durability[i] += weights[k];
        }
    }
}

int main() {
    fastio;
    
    cin >> n;
    durability.resize(n);
    weights.resize(n);
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        durability[i] = a;
        weights[i] = b;
    }
    dfs(0);
    cout << ans;
}
