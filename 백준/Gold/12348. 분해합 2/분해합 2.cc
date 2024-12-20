#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0);
#define all(v) v.begin(), v.end()
#define X first
#define Y second
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using piii = pair<int, pii>;
using piiii = pair<pii, pii>;

int main() {
    fastio;

    ll n;
    cin >> n;
    int digits = to_string(n).size();
    ll s = n - digits * 9;
    auto sumOfDigits = [](ll x) {
        int sum = 0;
        while (x) {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    };
    for (ll i = s; i < n; ++i) {
        if (n == i + sumOfDigits(i)) {
            cout << i;
            return 0;
        }
    }
    cout << 0;
}