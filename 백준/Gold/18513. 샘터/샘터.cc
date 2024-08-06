#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
using pii = pair<int, int>;
using i64 = long long;

int main() {
    fastio;

    int n, k;
    cin >> n >> k;
    unordered_set<int> vis;
    queue<pii> Q;
    for (int i = 0; i < n; ++i) {
        int srcLoc;
        cin >> srcLoc;
        vis.insert(srcLoc);
        Q.push({srcLoc, 0});
    }
    int cnt = 0;
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