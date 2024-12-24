#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
using ll = long long;

int main() {
    fastio;

    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> t(n<<1);
    for (int i = n; i < (n<<1); ++i) cin >> t[i];
    auto build = [&]() {
        for (int i = n-1; i; --i) t[i] = t[i<<1] + t[i<<1|1];
    };
    auto modify = [&](int p, ll val) {
        for (t[p += n] = val; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
    };
    auto query = [&](int l, int r) {
        ll res = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l&1) res += t[l++];
            if (r&1) res += t[--r];
        }
        return res;
    };
    m += k;
    build();
    while (m--) {
        int a;
        cin >> a;
        if (a == 1) {
            int b;
            ll c;
            cin >> b >> c;
            modify(b-1, c);
        } else {
            int b, c;
            cin >> b >> c;
            cout << query(b-1, c) << '\n';
        }
    }
}