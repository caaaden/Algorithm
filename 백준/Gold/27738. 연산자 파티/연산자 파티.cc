#include <bits/stdc++.h>

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
using pii = pair<int, int>;
using i64 = long long;

int main() {
    fastio;

    i64 n;
    cin >> n;
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    i64 x = 0;
    for (int i = (n/f)*f+1; i <= n; ++i) {
        if (i % a == 0) x += i;
        if (i % b == 0) x %= i;
        if (i % c == 0) x &= i;
        if (i % d == 0) x ^= i;
        if (i % e == 0) x |= i;
        if (i % f == 0) x >>= i;
    }
    cout << x;
}