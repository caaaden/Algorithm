#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> cards) {
    int n = cards.size();
    vector<int> vis(n);
    vector<int> groups;
    for (int i = 0; i < n; ++i) {
        if (vis[i]) continue;
        int idx = i;
        vis[idx] = 1;
        int cnt = 1;
        idx = cards[idx];
        while (!vis[idx-1]) {
            cnt++;
            vis[idx-1] = 1;
            idx = cards[idx-1];
        }
        groups.push_back(cnt);
    }
    sort(groups.rbegin(), groups.rend());
    if (groups.size() == 1) return 0;
    return groups[0] * groups[1];
}