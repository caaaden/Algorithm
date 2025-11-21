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
#define pb push_back
#define endl '\n'

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

//template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T, typename Compare = less<T>>
using ordered_set = tree<T, null_type, Compare, rb_tree_tag, tree_order_statistics_node_update>;

constexpr int dx[4] = {1, -1, 0, 0};
constexpr int dy[4] = {0, 0, 1, -1};
constexpr int dx2[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
constexpr int dy2[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
constexpr int bit = 9;
const long long MOD = 1e9 + 7;
const long long MOD2 = 1e9 + 9;
const int MAX = 1e9;

int main() {
    fastio;

    int p; cin >> p;
    vector<int> v(p);
    ll sum = 0;
    for (auto& e : v) {
        cin >> e;
        sum += e;
    }
    int a, b; cin >> a >> b;
    if (a < 0) {
        int k = abs(a) / p;
        k++;
        a += p * k, b += p * k;
    }
    // p의 배수, a가 0보다 크거나 같을 때까지
    // -13, p = 5
    // k = 3
    // abs(a) / p
    ll ans = 0;
    ans += (b/p - a/p) * sum;
    a %= p, b %= p;
    if (a <= b) {
        for (int i = a; i < b; ++i) {
            ans += v[i];
        }
    } else {
        for (int i = 0; i < b; ++i) {
            ans += v[i];
        }
        for (int i = a; i < p; ++i) {
            ans += v[i];
        }
        ans -= sum;
    }
    cout << ans;
    // 3 + 1
    // 1 + 2 + 3
    // 19
    // 4 + 6 + 19
    // 29
}