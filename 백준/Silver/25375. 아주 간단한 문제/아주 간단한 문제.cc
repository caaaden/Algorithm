#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin >> q;
    while (q--) {
        i64 a, b;
        cin >> a >> b;
        cout << (a != b && b % a == 0 ? 1 : 0) << '\n';
    }
}