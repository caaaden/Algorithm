#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> //required
#include <ext/pb_ds/tree_policy.hpp> //required
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace __gnu_pbds; //required
using namespace std;
template <typename T> using ordered_set =  tree<T, null_type, greater_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    fastio;

    auto eraseVal = [](ordered_set<int>& st, int val) {
        int idx = st.order_of_key(val);
        auto it = st.find_by_order(idx);
        if (*it == val) st.erase(it);
    };

    int n, m;
    cin >> n >> m;
    ordered_set<int> st;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        st.insert(x);
    }
    vector<int> v(m);
    for (auto& e : v) cin >> e;
    vector<int> v2(m);
    for (auto& e : v2) cin >> e;
    for (int i = 0; i < m; ++i) {
        auto it = st.find_by_order(v2[i]-1);
        if (it == st.end()) {
            cout << 0;
            return 0;
        }
        int present = *it;
        if (present >= v[i]) {
            eraseVal(st, present);
            present -= v[i];
            st.insert(present);
        } else {
            cout << 0;
            return 0;
        }
//        for (auto& e : st) cout << e << ' ';
//        cout << '\n';
    }
    cout << 1;
}