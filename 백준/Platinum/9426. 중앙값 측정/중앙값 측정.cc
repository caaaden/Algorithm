#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> //required
#include <ext/pb_ds/tree_policy.hpp> //required
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace __gnu_pbds; //required
using namespace std;
using i64 = long long;
//template <typename T> using ordered_map =  tree<T, T, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef tree<i64, null_type, greater_equal<i64>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
int main() {
    fastio;

    auto eraseVal = [](ordered_set& st, int val) {
        int idx = st.order_of_key(val);
        auto it = st.find_by_order(idx);
        if (*it == val) st.erase(it);
    };
    ordered_set st;
    int n, k;
    cin >> n >> k;
    queue<i64> Q;
    for (int i = 0; i < k; ++i) {
        i64 x;
        cin >> x;
        st.insert(x);
        Q.push(x);
    }
    i64 ans = 0;
    ans += *st.find_by_order(k/2);
    for (int i = 0; i < n-k; ++i) {
        eraseVal(st, Q.front());
        Q.pop();
        i64 x;
        cin >> x;
        st.insert(x);
        Q.push(x);
        ans += *st.find_by_order(k/2);
    }
    cout << ans;
}