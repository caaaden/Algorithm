#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastio;

    int n;
    cin >> n;
    string s;
    cin >> s;
    // abbcaccba
    // 4
    // cacc
    // vector<int> alpha(26) : 알파벳의 종류에 따른 개수
    // int cnt : 알파벳 종류의 개수
    vector<int> alpha(26);
    int cnt = 0;
    int l = 0, r = 0;
    int maxLen = 1;
    while (r < s.size()) {
        // 새롭게 추가해도 cnt <= n이면 계속 추가,
        // 새롭게 추가할 때 cnt > n이 되면 추가 x
        // cnt가 줄어들 때까지 l++
        char c = s[r] - 'a';
        // alpha[c] == 0
        // 새로운 종류의 알파벳
        if (!alpha[c]) {
            if (cnt == n) {
                // 더 이상 알파벳을 추가할 수 없음.
                // 왼쪽에서 빼줘야함.
                // cnt가 줄어들 때까지 빼줘야 함.
                while (cnt == n) {
                    char c2 = s[l] - 'a';
                    alpha[c2]--;
                    if (!alpha[c2]) {
                        cnt--;
                    }
                    l++;
                }
            } else {
                // cnt < n
                // 알파벳 추가 가능
                alpha[c]++;
                cnt++;
                r++;
            }
        } else {
            // 이미 있는 알파벳일 경우,
            // cnt와 상관없이 증가
            alpha[c]++;
            r++;
        }
        maxLen = max(maxLen, r-l);
    }
    cout << maxLen;
}