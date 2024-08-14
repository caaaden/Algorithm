#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main() {
    fastio;

    int n, l;
    cin >> n >> l;
    vector<int> v(n);
    for (auto& e : v) cin >> e;
    sort(v.begin(), v.end());
    int ans = 0;
    for (int s = 0, e = 0; e < n; s = e, ans++) for (; e < n && v[e]-v[s] <= l-1; ++e);
    cout << ans;
}