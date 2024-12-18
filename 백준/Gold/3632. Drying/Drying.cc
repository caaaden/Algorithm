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

    int n;
    cin >> n;
    vector<int> v(n);
    for (auto& e : v) cin >> e;
    int k;
    cin >> k;

    auto check = [&](int x) {
        ll timeTaken = 0;
        for (auto e : v) {
            e = max(e-x, 0);
            if (e) {
                if (k == 1) return false;
                timeTaken += e / (k-1);
                if (e % (k-1)) timeTaken++;
            }
        }
        return timeTaken <= x;
    };

    int lo = 0, hi = 1e9;
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) hi = mid;
        else lo = mid;
    }
    cout << lo+1;
}