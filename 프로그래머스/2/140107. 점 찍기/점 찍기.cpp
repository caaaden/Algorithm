#include <bits/stdc++.h>
using namespace std;
using ll = long long;

long long solution(int k, int d) {
    ll sum = 0;
    for (int i = 0; i*k <= d; ++i) {
        int x = i * k;
        int y = floor(sqrt((ll)d*d - (ll)x*x));
        sum += floor(y / k) + 1;
    }
    return sum;
}