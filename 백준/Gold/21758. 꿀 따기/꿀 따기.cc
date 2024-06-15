#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n+1);
    for (int i = 1; i <= n; ++i) cin >> v[i];
    vector<int> pSum(n+1);
    for (int i = 1; i <= n; ++i) pSum[i] = pSum[i-1] + v[i];
    int ans = INT_MIN;
    for (int i = 2; i <= n-1; ++i) {
        ans = max(ans, (pSum[n]-pSum[1])+(pSum[n]-pSum[i])-v[i]);
        ans = max(ans, pSum[i-1]+pSum[n-1]-v[i]);
        ans = max(ans, pSum[i]-pSum[1]+pSum[n-1]-pSum[i-1]);
    }
    cout << ans;
}