#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
using i64 = long long;

int main() {
    fastio;

    while (true) {
        i64 n;
        cin >> n;
        if (!n) break;
        int ans = 1;
        if (n > 0) {
            for (i64 i = 2; ans == 1 && i*i <= n; ++i) {
                i64 pow = i;
                for (int j = 2; j <= 30; ++j) {
                    pow *= i;
                    if (pow > n) break;
                    if (pow == n) {
                        ans = j;
                        break;
                    }
                }
            }
        } else {
            for (i64 i = -2; ans == 1 && i*i*i >= n; --i) {
                i64 pow = i;
                for (int j = 3; j <= 31; j += 2) {
                    pow *= i*i;
                    if (pow < n) break;
                    if (pow == n) {
                        ans = j;
                        break;
                    }
                }
            }
        }
        cout << ans << '\n';
    }
}