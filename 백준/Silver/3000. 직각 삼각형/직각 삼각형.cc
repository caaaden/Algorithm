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
    vector<int> cntA(100001), cntB(100001);
    for (auto& [a, b] : v) {
        cin >> a >> b;
        cntA[a]++;
        cntB[b]++;
    }
    i64 ans = 0;
    for (auto& [a, b] : v) ans += 1LL*(cntA[a]-1)*(cntB[b]-1);
    cout << ans;
}