#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int solution(int n, long long l, long long r) {
    cout << n << ' ' << l << ' ' << r << '\n';
    if (!n) return 1;
    // q1, r1, q2, r2
    ll power = 1;
    for (int i = 0; i < n-1; ++i) power *= 5;
    ll q1 = (l-1) / power;
    ll r1 = (l-1) % power + 1;
    ll q2 = (r-1) / power;
    ll r2 = (r-1) % power + 1;
    if (q1 == q2) {
        if (q1 == 2) return 0;
        return solution(n-1, r1, r2);
    } else {
        // q1 < q2
        // (0, 4), (3, 2)
        ll sum = 0;
        for (int i = q1; i <= q2; ++i) {
            if (i == q1) {
                if (i == 2) continue;
                sum += solution(n-1, r1, power);
            } else if (i == q2) {
                if (i == 2) continue;
                sum += solution(n-1, 1, r2);
                
            } else {
                if (i == 2) continue;
                sum += (1 << 2*n-2);
            }
        }
        return sum;
    }
    return 0; //
}