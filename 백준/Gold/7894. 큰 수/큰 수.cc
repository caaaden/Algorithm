#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
using i64 = long long;
using pii = pair<int, int>;

int main() {
    fastio;

    vector<double> pSum(10000001);
    pSum[1] = log10(1);
    for (int i = 2; i <= 10000000; ++i) pSum[i] = pSum[i-1] + log10(i);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << (int)pSum[n]+1 << '\n';
    }
}