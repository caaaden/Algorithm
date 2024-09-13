#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit) {
    // FF...FT...TT
    // 최소 T가 되게 하는 난이도 구하기
    // 숙련도 > 0
    // hi = max(diffs) + 1
    // lo = 0
    // x = 1일 때 true면 답 = 1
    // else lo = 1로 놓고 이분탐색
    
    int n = diffs.size();
    auto check = [&](int x) {
        ll time = 0;
        for (int i = 0; i < n; ++i) {
            time += times[i];
            if (i) time += max(0, diffs[i] - x) * (times[i] + times[i-1]);
        }
        return time <= limit;
    };
    // check(1)
    if (check(1)) return 1;
    int lo = 1, hi = *max_element(diffs.begin(), diffs.end()) + 1;
    while(lo + 1 < hi) {
        int mid = (lo + hi) >> 1;
        if (check(mid)) hi = mid;
        else lo = mid;
    }
    return lo+1;
}