#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using pii = pair<int, int>;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pii> v(n);
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first >> v[i].second;
        a[i] = v[i].first;
        b[i] = v[i].second;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    i64 ans = 0;
    for (int i = 0; i < n; ++i) {
        i64 x = upper_bound(a.begin(), a.end(), v[i].first) - lower_bound(a.begin(), a.end(), v[i].first) - 1;
        i64 y = upper_bound(b.begin(), b.end(), v[i].second) - lower_bound(b.begin(), b.end(), v[i].second) - 1;
        ans += x*y;
    }
    cout << ans;
}