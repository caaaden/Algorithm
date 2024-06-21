#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    unordered_map<int, int> mp;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        arr[i] = a;
        mp.insert({a, b});
    }
    sort(arr.begin(), arr.end());
    while (q--) {
        int u, v, x, y;
        cin >> u >> v >> x >> y;
        int s = lower_bound(arr.begin(), arr.end(), u) - arr.begin();
        int e = upper_bound(arr.begin(), arr.end(), v) - arr.begin() - 1;
        int cnt = 0;
        for (int i = s; i <= e; ++i) {
            int tmp = mp[arr[i]];
            if (x <= tmp && tmp <= y) cnt++;
        }
        cout << cnt << '\n';
    }
}