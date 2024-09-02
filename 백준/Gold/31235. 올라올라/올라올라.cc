#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define pb push_back
using namespace __gnu_pbds;
using namespace std;
using pii = pair<int, int>;
using ll = long long;
typedef tree<int, null_type, greater_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main() {
    fastio;

    int n;
    cin >> n;
    vector<int> v(n);
    for (auto& e : v) cin >> e;
    int cnt = 1;
    int ans = 1;
    int val = v[0];
    for (int i = 1; i < n; ++i) {
        if (v[i] < val) cnt++;
        else {
            if (v[i] > val) val = v[i];
            cnt = 1;
        }
        ans = max(ans, cnt);
    }
    cout << ans;
}