#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int solution(vector<vector<int>> targets) {
    // s 오름차순, e 오름차순
    int n = targets.size();
    vector<pii> v(n);
    for (int i = 0; i < n; ++i) v[i] = {targets[i][0], targets[i][1]};
    sort(v.begin(), v.end());
    // 현재 기준이 되는 막대의 e보다 비교 대상의 s가 작을 경우 continue
    // 같거나 클 경우 ans++
    int standard = v[0].second; // 기준
    int ans = 0;
    for (int i = 1; i < n; ++i) {
        // v[i].first와 standard를 비교
        if (standard > v[i].first) {
            standard = min(standard, v[i].second);
            continue;
        }
        ans++;
        standard = v[i].second;
    }
    ans++;
    return ans;
}