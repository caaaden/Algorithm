#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

const int MAX = 1'000'000;
int main() {
    fastio;

    vector<bool> isPrime(MAX+1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i*i <= MAX; ++i) {
        if (!isPrime[i]) continue;
        for (int j = i*i; j <= MAX; j += i) isPrime[j] = false;
    }
    int m, n;
    cin >> m >> n;
    for (int i = m; i <= n; ++i) if (isPrime[i]) cout << i << '\n';
}