#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

#define fastio ios::sync_with_stdio(0), cin.tie(0);
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
constexpr int MOD = 1e9;

int main()
{
    fastio;
    
    auto getDivisors = [](int x) {
        vector<int> divisors;
        for (int i = 1; i*i <= x; ++i) {
            if (x % i == 0) {
                divisors.push_back(i);
                if (i*i == x) continue;
                divisors.push_back(x/i);
            }
        }
        sort(all(divisors));
        return divisors;
    };
    int n;
    cin >> n;
    vector<int> d1 = getDivisors(n);
    vector<int> d2 = getDivisors(n+2);
    for (auto& a : d1) {
        int c = n / a;
        for (auto& b : d2) {
            int d = (n + 2) / b;
            d = -d;
            if (a * d + b * c == n + 1) {
                cout << a << ' ' << b << ' ' << c << ' ' << d;
                return 0;
            }
        }
    }
    cout << -1;
}