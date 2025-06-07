#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

#define fastio ios::sync_with_stdio(0), cin.tie(0)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define X first
#define Y second
#define rep(i, a, b) for (int i = a; i < b; ++i)

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using psi = pair<string, int>;
using piii = pair<int, pii>;
using piiii = pair<pii, pii>;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

constexpr int dx[4] = {1, -1, 0, 0};
constexpr int dy[4] = {0, 0, 1, -1};
constexpr int bit = 9;
const long long MOD = 1e9 + 7;

int main(){
    fastio;

    auto isNotInRange = [](int x) {
        return x < 1 || x > 13;
    };

    int A, B, C, D, E, F, G, H;
    cin >> A >> B >> C >> D >> E >> F >> G >> H;
    if (A+B+C+D != 91 || E+F+G+H != 91) {
        cout << 0;
        return 0;
    }
    int vis = 0;
    int ans = 0;
    for (int h = 1; h <= 13; ++h) {
        int d = D - h;
        if (isNotInRange(d)) continue;
        if (h == d) continue;
        vis |= 1 << h;
        vis |= 1 << d;
        for (int m = 1; m <= 13; ++m) {
            // m 중복 체크
            if (vis & (1 << m)) continue;
            int l = H - m;
            if (isNotInRange(l)) continue;
            if (m == l) continue;
            if (vis & (1 << l)) continue;
            vis |= 1 << m;
            vis |= 1 << l;
            for (int k = 1; k <= 13; ++k) {
                if (vis & (1 << k)) continue;
                vis |= 1 << k;
                for (int g = 1; g <= 13; ++g) {
                    if (vis & (1 << g)) continue;
                    int c = C - (g + k);
                    if (isNotInRange(c)) continue;
                    if (g == c) continue;
                    if (vis & (1 << c)) continue;
                    vis |= 1 << g;
                    vis |= 1 << c;
                    for (int j = 1; j <= 13; ++j) {
                        if (vis & (1 << j)) continue;
                        int i = G - (j + k);
                        if (isNotInRange(i)) continue;
                        if (j == i) continue;
                        if (vis & (1 << i)) continue;
                        vis |= 1 << j;
                        vis |= 1 << i;
                        for (int f = 1; f <= 13; ++f) {
                            if (vis & (1 << f)) continue;
                            int b = B - (f + j + m);
                            if (isNotInRange(b)) continue;
                            if (f == b) continue;
                            if (vis & (1 << b)) continue;
                            int e = F - (f + g + h);
                            if (isNotInRange(e)) continue;
                            if (f == e || b == e) continue;
                            if (vis & (1 << e)) continue;
                            int a = E - (b + c + d);
                            if (a != A - (e + i + l)) continue;
                            if (isNotInRange(a)) continue;
                            if (f == a || b == a || e == a) continue;
                            if (vis & (1 << a)) continue;
                            ans++;
                        }
                        vis &= ~(1 << j);
                        vis &= ~(1 << i);
                    }
                    vis &= ~(1 << g);
                    vis &= ~(1 << c);
                }
                vis &= ~(1 << k);
            }
            vis &= ~(1 << m);
            vis &= ~(1 << l);
        }
        vis &= ~(1 << h);
        vis &= ~(1 << d);
    }
    cout << ans;
}