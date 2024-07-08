#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main() {
    fastio;
    
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int nowX = 0, nowY = 0, dir = 0;
        int minX = 0, minY = 0, maxX = 0, maxY = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == 'R') {
                dir++;
                if (dir == 4) dir = 0;
            }
            if (s[i] == 'L') {
                dir--;
                if (dir == -1) dir = 3;
            }
            if (s[i] == 'F') {
                if (dir == 0) {
                    nowY++;
                    maxY = max(maxY, nowY);
                }
                if (dir == 1) {
                    nowX++;
                    maxX = max(maxX, nowX);
                }
                if (dir == 2) {
                    nowY--;
                    minY = min(minY, nowY);
                }
                if (dir == 3) {
                    nowX--;
                    minX = min(minX, nowX);
                }
            }
            if (s[i] == 'B') {
                if (dir == 0) {
                    nowY--;
                    minY = min(minY, nowY);
                }
                if (dir == 1) {
                    nowX--;
                    minX = min(minX, nowX);
                }
                if (dir == 2) {
                    nowY++;
                    maxY = max(maxY, nowY);
                }
                if (dir == 3) {
                    nowX++;
                    maxX = max(maxX, nowX);
                }
            }
        }
        cout << (maxX - minX) * (maxY - minY) << '\n';
    }
}