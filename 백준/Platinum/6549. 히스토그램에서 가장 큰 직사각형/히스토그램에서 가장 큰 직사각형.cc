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
const int MAX = 1e9;

int main(){
    fastio;

    int n;
    while (cin >> n) {
        if (!n) return 0;
        vector<int> v(n+2);
        v[0] = -1, v[n+1] = -1;
        for (int i = 1; i <= n; ++i) cin >> v[i];
        vector<int> leftFirstSmallerIndex(n + 1);
        vector<int> rightFirstSmallerIndex(n + 1);
        stack<pii> s;
        s.push({v[0], 0});
        for (int i = 1; i <= n; ++i) {
            while (s.top().X >= v[i]) s.pop();
            leftFirstSmallerIndex[i] = s.top().Y;
            s.push({v[i], i});
        }
        s = stack<pii>();
        s.push({v[n+1], n+1});
        for (int i = n; i >= 1; --i) {
            while (s.top().X >= v[i]) s.pop();
            rightFirstSmallerIndex[i] = s.top().Y;
            s.push({v[i], i});
        }
        ll ans = 0;
        for (int i = 1; i <= n; ++i) {
            ll width = rightFirstSmallerIndex[i];
            width -= leftFirstSmallerIndex[i] + 1;
            ans = max(ans, width * v[i]);
        }
        cout << ans << '\n';
    }
}