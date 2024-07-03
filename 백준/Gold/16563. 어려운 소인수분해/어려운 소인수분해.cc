#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
using pii = pair<int, int>;

int main() {
    fastio;

    vector<bool> isPrime(5000001, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i*i <= 5000000; ++i) {
        if (!isPrime[i]) continue;
        for (int j = i*i; j <= 5000000; j += i) isPrime[j] = false;
    }
    vector<int> primes;
    for (int i = 2; i*i <= 5000000; ++i) if (isPrime[i]) primes.push_back(i);
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto& e : v) cin >> e;
    for (int i = 0; i < n; ++i) {
        for (auto& p : primes) {
            if (v[i] < p) break;
            while (v[i] % p == 0) {
                cout << p << ' ';
                v[i] /= p;
            }
        }
        if (v[i] > 1) cout << v[i];
        cout << '\n';
    }
}
