#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main() {
    fastio;

    int n;
    cin >> n;
    vector<int> ans(n);
    for (int i = 1, x; i <= n; ++i) {
        cin >> x;
        for (int j = 0, cnt = 0; j < n; ++j) {
            if (ans[j]) continue;
            if (cnt == x) {
                ans[j] = i;
                break;
            }
            cnt++;
        }
    }
    for (auto& e : ans) cout << e << ' ';
}
