#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastio;

    int n;
    cin >> n;
    vector<int> v(n);
    for (auto& e : v) cin >> e;
    stack<int> st;
    string ans;
    for (int i = 1, idx = 0; i <= n; ++i) {
        st.push(i);
        ans += "+\n";
        while (st.size() && st.top() == v[idx]) {
            st.pop();
            ans += "-\n";
            idx++;
        }
    }
    cout << (st.empty() ? ans : "NO");
}