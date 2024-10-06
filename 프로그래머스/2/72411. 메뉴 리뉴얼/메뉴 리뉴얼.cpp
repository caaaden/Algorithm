#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) {
    unordered_map<string, int> mp;
    for (auto& order : orders) {
        int n = order.size();
        for (int i = 0; i < (1 << n); ++i) {
            int cnt = 0;
            string combSelected;
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) {
                    cnt++;
                    combSelected += order[j];
                }
            }
            if (cnt < 2) continue;
            sort(all(combSelected));
            mp[combSelected]++;
        }
    }
    vector<string> ans;
    for (auto& num : course) {
        vector<string> comb;
        int mmax = 0;
        for (auto& [a, b] : mp) {
            if (b == 1) continue;
            if (a.size() != num) continue;
            if (b >= mmax) {
                if (b > mmax) {
                    comb.clear();
                    mmax = b;
                }
                comb.push_back(a);
            }
        }
        for (auto& e : comb) ans.push_back(e);
    }
    sort(all(ans));
    return ans;
}