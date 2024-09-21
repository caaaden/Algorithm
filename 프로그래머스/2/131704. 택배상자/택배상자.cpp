#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> order) {

    stack<int> st, st2; // 1...n, 보조
    int n = order.size();
    // 1...n
    for (int i = n; i >= 1; --i) {
        st.push(i);
    }
    // st.top(), st2.top()에서 찾는다
    // 없으면 st.top() < e이면 다음단계로
    // 그게 아닐 경우 i를 return
    int i = 0;
    while (i < n) {
        // bool flag = true;
        if (st2.size() && st2.top() == order[i]) {
            // if (flag) flag = false;
            ++i;
            st2.pop();
        } else {
            if (st.size()) {
                if (st.top() == order[i]) {
                    ++i;
                    st.pop();    
                } else {
                    if (st.top() > order[i]) {
                        return i;
                    }
                    st2.push(st.top());
                    st.pop();
                }
                // 2 3
                // 5
            }    
        }
        
    }
    return n;
}