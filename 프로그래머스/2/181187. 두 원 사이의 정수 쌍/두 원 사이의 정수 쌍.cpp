#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solution(int r1, int r2) {
    ll ans = 0;
    for (ll i = 1; i < r1; ++i) {
        ll y = floor(sqrt((ll)r2 * r2 - i * i));
        ll y2 = ceil(sqrt((ll)r1 * r1 - i * i));
        ans += y - y2 + 1;
    }
    for (ll i = r1; i < r2; ++i) {
        ll y = floor(sqrt((ll)r2 * r2 - i * i));
        ans += y;
    }
    ans += r2 - r1 + 1;
    ans *= 4;
    return ans;
}