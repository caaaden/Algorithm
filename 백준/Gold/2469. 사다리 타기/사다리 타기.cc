#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastio;
    
    int k, n;
    cin >> k >> n;
    vector<int> top(k), bottom(k);
    for (int i = 0; i < k; ++i) top[i] = i;
    for (int i = 0; i < k; ++i) {
        char c;
        cin >> c;
        bottom[c - 'A'] = i;
    }
    vector<string> ladder(n);
    int hiddenLine;
    for (int i = 0; i < n; ++i) {
        cin >> ladder[i];
        if (ladder[i][0] == '?') hiddenLine = i;
    }
    for (int i = 0; i < hiddenLine; ++i) {
        for (int j = 0; j < k; ++j) {
            if (top[j] == 0) {
                if (ladder[i][top[j]] == '*') continue;
                top[j]++;
            } else if (top[j] == k-1) {
                if (ladder[i][top[j]-1] == '*') continue;
                top[j]--;
            } else {
                if (ladder[i][top[j]-1] == '*' && ladder[i][top[j]] == '*') continue;
                if (ladder[i][top[j]-1] == '-') top[j]--;
                else top[j]++;
            }
        }
    }
    for (int i = n-1; i > hiddenLine; --i) {
        for (int j = 0; j < k; ++j) {
            if (bottom[j] == 0) {
                if (ladder[i][bottom[j]] == '*') continue;
                bottom[j]++;
            } else if (bottom[j] == k-1) {
                if (ladder[i][bottom[j]-1] == '*') continue;
                bottom[j]--;
            } else {
                if (ladder[i][bottom[j]-1] == '*' && ladder[i][bottom[j]] == '*') continue;
                if (ladder[i][bottom[j]-1] == '-') bottom[j]--;
                else bottom[j]++;
            }
        }
    }
    vector<int> top2(k), bottom2(k);
    for (int i = 0; i < k; ++i) {
        top2[top[i]] = i;
        bottom2[bottom[i]] = i;
    }
    string ans;
    bool flag = true;
    for (int i = 0; i < k-1; ++i) {
        if (top2[i] == bottom2[i]) ans += '*';
        else if (top2[i] == bottom2[i+1] && top2[i+1] == bottom2[i]) {
            if (i == k-2) ans += '-';
            else {
                ans += "-*";
                ++i;
            }
        } else {
            flag = false;
            break;
        }
    }
    if (flag) cout << ans;
    else for (int i = 0; i < k-1; ++i) cout << 'x';
}