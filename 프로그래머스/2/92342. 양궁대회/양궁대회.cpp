#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int n, vector<int> info) {
    // choice or not
    // for 2^11 cases
    vector<int> ans;
    int maxDiff = INT_MIN;
    for (int i = 0; i < (1 << 11); ++i) {
        int apeach = 0, lion = 0; // 얻은 점수
        int arrows = 0; // lion이 사용한 화살의 개수
        vector<int> arrowsByTargets(11);
        for (int j = 0; j < 11; ++j) {
            if (i & (1 << j)) {
                // lion이 점수를 흭득하는 경우
                arrows += info[j] + 1;
                arrowsByTargets[j] = info[j] + 1;
                lion += 10 - j;
            } else {
                if (info[j]) {
                    apeach += 10 - j;
                }
            }
        }
        if (arrows <= n) {
            // arrows < n인 경우 남은 arrows를 모두 소모해야함
            // 결과를 바꾸지 않으면서 소모하기
            
            
            int diff = lion - apeach;
            if (maxDiff <= diff) {
                if (arrows < n) {
                    int left = n - arrows;
                    // 결과를 바꾸지 않으면서 남은 화살을 모두 소모하기
                    for (int i = 10; i >= 0; --i) {
                        // info, arrowsByTargets 비교
                        if (info[i] < arrowsByTargets[i]) {
                            arrowsByTargets[i] += left;
                            break;
                        } else {
                            // apeach가 이긴 경우
                            while (left && info[i] > arrowsByTargets[i]+1) {
                                arrowsByTargets[i]++;
                                left--;
                            }
                        }
                    }
                }
                if (maxDiff == diff) {
                    for (int i = 10; i >= 0; --i) {
                        // ans, arrowsByTargets
                        if (ans[i] == arrowsByTargets[i]) continue;
                        if (ans[i] < arrowsByTargets[i]) {
                            ans = arrowsByTargets;
                            break;
                        }
                    }
                } else {
                    maxDiff = diff;
                    ans = arrowsByTargets;    
                }
            }
        }
    }
    if (maxDiff <= 0) return {-1};
    return ans;
}