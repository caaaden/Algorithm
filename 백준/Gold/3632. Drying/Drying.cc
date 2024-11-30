#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0);
#define all(v) v.begin(), v.end()
#define X first
#define Y second
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using piii = pair<int, pii>;

int main() {
    fastio;

    // FF...FT...TT
    // lo = 0, hi = 1e9
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (auto& e : v) cin >> e;
    ll k;
    cin >> k;

    auto check = [&](ll x) {
        ll timeTaken = 0;
        for (auto e : v) {
            e = max(e-x, 0LL);
            if (e) {
                if (k == 1) return false;
                timeTaken += e / (k-1);
                if (e % (k-1)) timeTaken++;
            }
        }
        return timeTaken <= x;
    };

    ll lo = 0, hi = 1e9+10;
    while (lo + 1 < hi) {
        ll mid = (lo + hi) / 2;
        if (check(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    cout << lo+1;
}