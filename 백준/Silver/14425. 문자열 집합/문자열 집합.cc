#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main() {
    fastio;

    int n, m;
    cin >> n >> m;
    unordered_set<string> st;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        st.insert(s);
    }
    int cnt = 0;
    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s;
        if (st.count(s)) cnt++;
    }
    cout << cnt;
}