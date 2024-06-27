#include <bits/stdc++.h>

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main() {
    fastio;

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(6);
        for (auto& e : v) cin >> e;
        int sum = 0;
        int sumOfSum = 0;
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