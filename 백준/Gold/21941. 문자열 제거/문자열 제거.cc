#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastio;

    string s;
    cin >> s;
    int m;
    cin >> m;
    unordered_map<string, int> mp;
    for (int i = 0; i < m; ++i) {
        string a;
        int x;
        cin >> a >> x;
        reverse(a.begin(), a.end());
        mp.insert({a, x});
    }
    vector<int> dp(s.size());
    for (int i = 0; i < dp.size(); ++i) dp[i] = i+1;
    for (int i = 0; i < dp.size(); ++i) {
        string tmp;
        for (int j = i; j >= 0; --j) {
            tmp += s[j];
            if (mp.count(tmp)) {
                if (j == 0) dp[i] = max(dp[i], mp[tmp]);
                else dp[i] = max(dp[i], dp[j-1] + mp[tmp]);
            }
        }
        if (i > 0) dp[i] = max(dp[i], dp[i-1] + 1);
    }
    cout << dp[s.size()-1];
}