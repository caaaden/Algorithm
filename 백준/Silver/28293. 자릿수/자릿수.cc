#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
using i64 = long long;
using pii = pair<int, int>;

int main() {
    fastio;

    int a, b;
    cin >> a >> b;
    // log10(a) * b
    cout << (int)(log10(a)*b)+1;
}