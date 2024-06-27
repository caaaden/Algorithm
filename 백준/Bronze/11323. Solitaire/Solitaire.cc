#include <bits/stdc++.h>

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
using i64 = long long;

int main() {
    fastio;

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<i64> v(6);
        for (auto& e : v) cin >> e;
        i64 sum = 0;
        i64 sumOfSum = 0;
        for (int i = 0, cnt = 0; cnt < 6; ++i) {
            if (sum+v[i%6] <= n) {
                if (cnt) cnt = 0;
                sum += v[i%6];
                sumOfSum += sum;
            } else {
                cnt++;
            }
        }
        cout << sumOfSum << '\n';
    }
}