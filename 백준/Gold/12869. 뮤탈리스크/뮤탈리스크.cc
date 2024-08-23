#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main() {
    fastio;
    
    int n;
    cin >> n;
    vector<int> v(3);
    for (int i = 0; i < n; ++i) cin >> v[i];
    vector<vector<vector<int>>> dp(61, vector<vector<int>>(61, vector<int>(61)));
    int cnt = INT_MAX;
    function<void(int, int, int, int)> solve = [&](int a, int b, int c, int depth) {
        if (a <= 0 && b <= 0 && c <= 0) {
            cnt = min(cnt, depth);
            return;
        }
        if (a < 0) a = 0;
        if (b < 0) b = 0;
        if (c < 0) c = 0;
        if (dp[a][b][c] <= depth && dp[a][b][c]) return;
        dp[a][b][c] = depth;
        solve(a-9, b-3, c-1, depth+1);
        solve(a-9, b-1, c-3, depth+1);
        solve(a-3, b-9, c-1, depth+1);
        solve(a-3, b-1, c-9, depth+1);
        solve(a-1, b-9, c-3, depth+1);
        solve(a-1, b-3, c-9, depth+1);
    };
    solve(v[0], v[1], v[2], 0);
    cout << cnt;
}