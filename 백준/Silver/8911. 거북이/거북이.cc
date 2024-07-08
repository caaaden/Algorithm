#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int main() {
    fastio;
    
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
                    x += dx[dir];
                    y += dy[dir];
                } else {
                    x -= dx[dir];
                    y -= dy[dir];
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
