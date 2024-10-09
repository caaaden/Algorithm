#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define all(v) (v).begin(), (v).end()
using namespace __gnu_pbds;
using namespace std;
using pii = pair<int, int>;
using i64 = long long;
typedef tree<i64, null_type, less<i64>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main() {
    fastio;
    
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto& e : v) cin >> e;
    int rangeSum = v[0];
    int ans = v[0];
    for (int i = 1; i < n; ++i) {
        if (rangeSum < 0) rangeSum = v[i];
        else rangeSum += v[i];
        ans = max(ans, rangeSum);
    }
    cout << ans;
}