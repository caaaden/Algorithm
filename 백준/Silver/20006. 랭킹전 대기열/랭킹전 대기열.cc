#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
using pis = pair<int, string>;

bool cmp(const pis& a, const pis& b) {
    return a.second < b.second;
}

int main() {
    fastio;
    
    int p, m;
    cin >> p >> m;
    vector<vector<pis>> Q; // 대기열
    for (int i = 0; i < p; ++i) {
        int l;
        string n;
        cin >> l >> n;
        bool flag = false; // 어떤 방에도 들어가지 못했을 경우.
        for (auto& room : Q) {
            if (room.size() == m) continue; // 방이 다 찼을 경우
            // 방이 다 차지 않았을 경우 최소 한 명 이상으로 이루어져 있음. 즉 room[0] : 첫 번째 플레이어는 항상 존재.
            int firstPlayersLevel = room[0].first;
            if (firstPlayersLevel-10 <= l && l <= firstPlayersLevel+10) {
                room.push_back({l, n});
                flag = true;
                break;
            }
        }
        if (flag) continue; // 이미 생성된 방에 들어갔을 경우.
        vector<pis> R; // 새로운 방 개설.
        R.push_back({l, n});
        Q.push_back(R);
    }
    for (auto& room : Q) {
        sort(room.begin(), room.end(), cmp);
        if (room.size() == m) {
            cout << "Started!" << '\n';
        } else {
            cout << "Waiting!" << '\n';
        }
        for (auto& [l, n] : room) {
            cout << l << ' ' << n << '\n';
        }
    }
}