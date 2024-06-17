#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin >> q;
    i64 now = 1;
    i64 p = 1;
    while (q--) {
        int what;
        cin >> what;
        if (what == 0) {
            int x;
            cin >> x;
            now += x;
        } else if (what == 1) {
            i64 x;
            cin >> x;
            now *= x;
            p *= x;
        } else if (what == 2) {
            i64 n;
            cin >> n;
            now += n*p;
        } else {
            cout << now << '\n';
        }
    }
}