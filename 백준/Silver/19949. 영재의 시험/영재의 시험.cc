#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int ans, score;
int check[10], v[10];
void dfs(int k) {
    if (k == 10) {
        if (score >= 5) ans++;
        return;
    }
    for (int i = 1; i <= 5; ++i) {
        check[k] = i;
        if (k >= 2) {
            if (check[k-2] == check[k-1] && check[k-1] == check[k]) continue;
        }
        if (v[k] == check[k]) score++;
        dfs(k+1);
        if (v[k] == check[k]) score--;
    }
}

int main() {
    fastio;
    
    for (int i = 0; i < 10; ++i) cin >> v[i];
    dfs(0);
    cout << ans;
}