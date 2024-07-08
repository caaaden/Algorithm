#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main() {
    fastio;

    // 이동하면서 현재 위치 (x, y)의 최댓값과 최솟값을 갱신.
    // 영역 계산 후 출력

    // 0, 0; 북쪽

    int t;
    cin >> t;
    while (t--) {
        string command;
        cin >> command;
        int x = 0, y = 0;
        int dir = 0;
        int maxX = 0, maxY = 0, minX = 0, minY = 0;
        for (auto& c : command) {
            if (c == 'L') {
                dir--;
                if (dir < 0) dir += 4;
            } else if (c == 'R') {
                dir++;
                if (dir > 3) dir -= 4;
            } else {
                if (c == 'F') {
                    if (dir == 0) x--;
                    else if (dir == 1) y++;
                    else if (dir == 2) x++;
                    else y--;
                } else {
                    if (dir == 0) x++;
                    else if (dir == 1) y--;
                    else if (dir == 2) x--;
                    else y++;
                }
                maxX = max(maxX, x);
                maxY = max(maxY, y);
                minX = min(minX, x);
                minY = min(minY, y);
            }
        }
        cout << (maxX - minX) * (maxY - minY) << '\n';
    }
}
