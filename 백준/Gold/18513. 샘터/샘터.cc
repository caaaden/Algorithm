#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
using pii = pair<int, int>;
using i64 = long long;

int main() {
    fastio;

    int n, k;
    cin >> n >> k;
    // 방문 여부를 set으로 관리
    unordered_set<int> vis;
    // {위치, 샘터로부터의 거리}
    // cnt == k일 때 불행도의 합을 출력
    queue<pii> Q;
    for (int i = 0; i < n; ++i) {
        int srcLoc;
        cin >> srcLoc;
        vis.insert(srcLoc);
        Q.push({srcLoc, 0});
    }
    int cnt = 0; // 설치한 집의 수
    i64 unhappiness = 0;
    while (true) {
        int now = Q.front().first;
        int dist = Q.front().second;
        Q.pop();
        for (auto& next : {now+1, now-1}) {
            if (vis.count(next)) continue;
            vis.insert(next);
            cnt++;
            unhappiness += (dist+1);
            if (cnt == k) {
                cout << unhappiness;
                return 0;
            }
            Q.push({next, dist+1});
        }
    }
}