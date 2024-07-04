#include <bits/stdc++.h>
using namespace std;

int n;
int a[14]; // col
int b[27]; // r-dg
int c[27]; // l-dg
int cnt = 0;
void dfs(int k) {
    if (k == n) {
        // cases completed
        cnt++;
        return;
    }
    
    // k = 행. 0 ... n-1
    for (int i = 0; i < n; ++i) {
        if (a[i]) continue;
        // k행, i열.
        if (b[k-i+n-1]) continue;
        // r-dg
        if (c[k+i]) continue;
        // l-dg
        a[i] = 1;
        b[k-i+n-1] = 1;
        c[k+i] = 1;
        dfs(k+1);
        a[i] = 0;
        b[k-i+n-1] = 0;
        c[k+i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    dfs(0);
    cout << cnt;
}