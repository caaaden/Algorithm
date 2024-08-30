#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define rep(i, a, b) for (int i = a; i < b; ++i)
using namespace __gnu_pbds;
using namespace std;
using pii = pair<int, int>;
using i64 = long long;
//typedef tree<i64, null_type, less_equal<i64>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main() {
    fastio;

    int n;
    cin >> n;
    vector<int> v(n);
    for (auto& e : v) cin >> e;
    vector<int> v2 = v;
    sort(v2.begin(), v2.end());
    unordered_map<int, int> mp;
    int idx = 0;
    for (auto& e : v2) {
        if (mp.count(e)) continue;
        mp[e] = idx++;
    }
    for (auto& e : v) cout << mp[e] << ' ';
}