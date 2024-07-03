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
    for (int i = 2; i*i <= 5000000; ++i) {
        if (isPrime[i]) primes.push_back(i);
    }
    // 한꺼번에 소인수분해 하기.
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto& e : v) cin >> e;
    vector<vector<int>> divisors(n);
    for (auto& p : primes) {
        for (int i = 0; i < n; ++i) {
            // v[i]를 p로 나누기,
            while (v[i] % p == 0) {
                divisors[i].push_back(p);
                v[i] /= p;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (v[i] > 1) divisors[i].push_back(v[i]);
    }
    for (int i = 0; i < n; ++i) {
        for (auto& e : divisors[i]) {
            cout << e << ' ';
        }
        cout << '\n';
    }
}
