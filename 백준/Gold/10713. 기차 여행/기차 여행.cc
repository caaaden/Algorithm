#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0);
#define all(v) v.begin(), v.end()
#define X first
#define Y second
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
    fastio;

    int n, m;
    cin >> n >> m;
    vector<int> cities(m);
    for (auto& e : cities) cin >> e;
    vector<int> a(n), b(n), c(n);
    for (int i = 1; i < n; ++i) cin >> a[i] >> b[i] >> c[i];
    vector<int> pSum(n+1);
    for (int i = 0; i < m-1; ++i) {
        int x = cities[i];
        int y = cities[i+1];
        if (x > y) swap(x, y);
        pSum[x]++;
        pSum[y]--;
    }
    for (int i = 2; i <= n; ++i) pSum[i] += pSum[i-1];
    ll ans = 0;
    for (int i = 1; i < n; ++i) {
        int x = c[i] / (a[i] - b[i]);
        if (pSum[i] > x) ans += (ll)pSum[i] * b[i] + c[i];
        else ans += (ll)pSum[i] * a[i];
    }
    cout << ans;
}