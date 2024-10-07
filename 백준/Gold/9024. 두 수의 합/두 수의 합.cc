#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define pb push_back
#define X first
#define Y second
#define all(v) v.begin(), v.end()
using namespace __gnu_pbds;
using namespace std;
using pii = pair<int, int>;
using ll = long long;
typedef tree<int, null_type, greater_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main() {
    fastio;

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        for (auto& e : v) cin >> e;
        sort(all(v));
        int minDiff = INT_MAX;
        int cnt = 0;
        for (int i = 0; i < n-1; ++i) {
            int target = k - v[i];
            int idx = lower_bound(v.begin()+i+1, v.end(), target) - v.begin();
            if (idx != i+1) {
                int diff = target - v[idx-1];
                if (minDiff > diff) {
                    minDiff = diff;
                    cnt = 1;
                } else if (minDiff == diff) cnt++;
            }
            if (idx != n) {
                int diff = v[idx] - target;
                if (minDiff > diff) {
                    minDiff = diff;
                    cnt = 1;
                } else if (minDiff == diff) {
                    cnt++;
                }
            }
        }
        cout << cnt << '\n';
    }
}