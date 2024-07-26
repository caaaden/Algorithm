#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using pii = pair<int, int>;

pii dfs(string num) {
    if (num.size() == 1) {
        if (num[0] - '0' & 1) {
            return {1, 1};
        } else {
            return {0, 0};
        }
    } else if (num.size() == 2) {
        // num에서 홀수 개수 구하기,
        // 연산을 통해 얻은 숫자로부터 나올 수 있는 홀수 개수의 최댓값 최솟값 구하기
        int a = num[0] - '0';
        int b = num[1] - '0';
        int cnt = 0;
        cnt += a & 1;
        cnt += b & 1;
        cnt += dfs(to_string(a+b)).first;
        return {cnt, cnt};
    } else {
        // 자를 위치 정하기
        int cnt = 0;
        for (auto& c : num) {
            int x = c - '0';
            if (x & 1) cnt++;
        }
        int mmax = INT_MIN;
        int mmin = INT_MAX;
        for (int i = 0; i < num.size()-2; ++i) {
            for (int j = i+1; j < num.size()-1; ++j) {
                string a = num.substr(0, i+1);
                string b = num.substr(i+1, j-i);
                string c = num.substr(j+1);
                int x = stoi(a) + stoi(b) + stoi(c);
                pii cnt2 = dfs(to_string(x));
                mmax = max(mmax, cnt2.first);
                mmin = min(mmin, cnt2.second);
            }
        }
        return {cnt+mmax, cnt+mmin};
    }
}

int main() {
    fastio;

    string s;
    cin >> s;
    pii ans = dfs(s);
    cout << ans.second << ' ' << ans.first;
}