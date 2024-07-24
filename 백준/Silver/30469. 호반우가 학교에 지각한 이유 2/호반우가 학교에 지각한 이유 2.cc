#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastio;

    // 1 -> 1
    // 3 -> 1
    // 7 -> 1
    // 9 -> 7 -> 1

    // 1 -> ... -> 1

    // 1 -> 1
    // 1 -> 3
    // 1 -> 7
    // 1 -> 9

    int a, b, n;
    cin >> a >> b >> n;
    // b의 십의 자리 수가 1, 3, 7, 9가 아니면 -1
    for (auto& e : {2, 4, 5, 6, 8}) {
        if (b / 10 == e) {
            cout << -1;
            return 0;
        }
    }
    cout << a;
    if (a % 10 == 9) {
        cout << 7;
        for (int i = 0; i < n-5; ++i) cout << 1;
    } else {
        for (int i = 0; i < n-4; ++i) cout << 1;
    }
    cout << b;

}