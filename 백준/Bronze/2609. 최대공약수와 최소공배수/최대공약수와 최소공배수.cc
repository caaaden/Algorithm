#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main() {
    fastio;

    function<int(int, int)> getGCD = [&](int a, int b) {
        if (!b) return a;
        return getGCD(b, a%b);
    };
    int a, b;
    cin >> a >> b;
    int gcd = getGCD(a, b);
    int lcm = (a * b) / gcd;
    cout << gcd << '\n' << lcm;
}