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

    auto digitSquareSum = [](int x) {
        int sum = 0;
        while (x) {
            int r = x % 10;
            sum += r * r;
            x /= 10;
        }
        return sum;
    };

    vector<int> next(730);
    for (int i = 1; i < 730; ++i) {
        int now = i;
        while (!next[now]) {
            int nxt = digitSquareSum(now);
            next[now] = nxt;
            now = nxt;
        }
    }

    auto generateSequence = [&next, &digitSquareSum](int x) {
        vector<int> vis(730);
        vector<int> ret;
        if (x >= 730) {
            ret.push_back(x);
            x = digitSquareSum(x);
        }
        while (!vis[x]) {
            vis[x] = 1;
            ret.push_back(x);
            x = next[x];
        }
        return ret;
    };

    while (true) {
        int a, b; cin >> a >> b;
        if (a == 0 && b == 0) break;
        vector<int> seqA, seqB;
        seqA = generateSequence(a);
        seqB = generateSequence(b);
        int ans = 1e9;
        for (int i = 0; i < seqA.size(); ++i) {
            for (int j = 0; j < seqB.size(); ++j) {
                if (seqA[i] != seqB[j]) continue;
                ans = min(ans, i+j+2);
            }
        }
        cout << a << ' ' << b << ' ' << (ans == 1e9 ? 0 : ans) << endl;
    }
}