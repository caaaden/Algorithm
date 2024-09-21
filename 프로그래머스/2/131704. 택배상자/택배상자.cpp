#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> order) {

    stack<int> st;
    int ans = 0;
    for (int i = 1; i <= order.size(); ++i) {
        st.push(i);
        while (st.size() && st.top() == order[ans]) {
            st.pop();
            ans++;
        }
    }
    return ans;
}