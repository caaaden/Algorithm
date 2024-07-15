#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastio;

    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> alpha(26);
    int cnt = 0;
    int l = 0, r = 0;
    int maxLen = 1;
    while (r < s.size()) {
        char c = s[r] - 'a';
        if (!alpha[c]) {
            if (cnt == n) {
                while (cnt == n) {
                    char c2 = s[l] - 'a';
                    alpha[c2]--;
                    if (!alpha[c2]) cnt--;
                    l++;
                }
            } else {
                alpha[c]++;
                cnt++;
                r++;
            }
        } else {
            alpha[c]++;
            r++;
        }
        maxLen = max(maxLen, r-l);
    }
    cout << maxLen;
}