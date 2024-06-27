#include <bits/stdc++.h>

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main() {
    fastio;

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (auto& e : a) cin >> e;
    while (m--) {
        int x;
        cin >> x;
        if (binary_search(a.begin(), a.end(), x)) {
            cout << k << '\n';
        } else {
            int idx = lower_bound(a.begin(), a.end(), x) - a.begin();
            if (idx == 0) {
                cout << max(k-(a[idx]-x), 0) << '\n';
            } else if (idx == n) {
                cout << max(k-(x-a[idx-1]), 0) << '\n';
            } else {
                cout << max(max(k-(a[idx]-x), 0), max(k-(x-a[idx-1]), 0)) << '\n';
            }
        }
    }
}