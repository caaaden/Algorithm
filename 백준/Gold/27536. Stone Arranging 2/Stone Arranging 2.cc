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

int main() {
    fastio;
    
    unordered_map<int, int> lastIdx;
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        lastIdx[v[i]] = i;
    }
    for (int idx = 0; idx < n; ) {
        for (int i = 0; i < lastIdx[v[idx]] - idx + 1; ++i) {
            cout << v[idx] << '\n';
        }
        idx = lastIdx[v[idx]] + 1;
    }
}