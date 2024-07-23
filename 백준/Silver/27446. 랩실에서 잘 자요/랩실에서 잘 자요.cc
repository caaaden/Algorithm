#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastio;

    int n, m;
    cin >> n >> m;
    vector<int> check(n+1);
    for (int i = 0; i < m; ++i) {
        int page;
        cin >> page;
        check[page] = 1;
    }
    vector<int> v;
    for (int i = 1; i <= n; ++i) {
        if (check[i]) continue;
        v.push_back(i);
    }
    // 1, 2, 6, 8
    int cnt = 0;
    int prev;
    int ans = 0;
    for (int i = 0; i < v.size(); ++i) {
        if (!cnt) {
            cnt = 1;
            prev = v[i];
        } else {
            if (v[i] - prev <= 3) {
                cnt += v[i] - prev;
                prev = v[i];
            } else {
                ans += 5 + 2 * cnt;
                cnt = 1;
                prev = v[i];
            }
        }
    }
    ans += 5 + 2 * cnt;
    cout << (v.empty() ? 0 : ans);
}