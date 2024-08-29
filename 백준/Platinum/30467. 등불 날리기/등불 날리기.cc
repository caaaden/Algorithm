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
typedef tree<i64, null_type, less_equal<i64>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<i64, null_type, greater_equal<i64>, rb_tree_tag, tree_order_statistics_node_update> ordered_set2;

int main() {
    fastio;

    ordered_set SET;
    ordered_set2 SET2;
    queue<i64> Q;
    auto erase2 = [](ordered_set& SET, int val) {
        int idx = SET.order_of_key(val);
        auto it = SET.find_by_order(idx);
        if (*it == val) SET.erase(it);
    };
    auto erase3 = [](ordered_set2& SET, int val) {
        int idx = SET.order_of_key(val);
        auto it = SET.find_by_order(idx);
        if (*it == val) SET.erase(it);
    };
    int n, s;
    cin >> n >> s;
    i64 ans = 0;
    i64 sum = 0;
    rep(i, 0, s) {
        i64 x;
        cin >> x;
        Q.push(x);
        SET.insert(x);
        SET2.insert(x);
        sum += SET.order_of_key(x);
    }
    ans = max(ans, sum);
    rep(i, 0, n-s) {
        sum -= SET2.order_of_key(Q.front());
        erase3(SET2, Q.front());
        erase2(SET, Q.front());
        Q.pop();
        i64 x;
        cin >> x;
        Q.push(x);
        SET.insert(x);
        SET2.insert(x);
        sum += SET.order_of_key(x);
        ans = max(ans, sum);
    }
    cout << ans;
}