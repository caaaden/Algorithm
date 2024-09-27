#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    // check[a][b][c] = (a, b)에 c시간에 존재하는 로봇의 개수
    vector<vector<vector<int>>> check(101, vector<vector<int>>(101, vector<int>(20000)));
    int n = points.size();
    int m = routes[0].size();
    int ans = 0;
    for (auto& route : routes) {
        int t = 0;
        for (int i = 0; i < m-1; ++i) {
            // route[i], route[i+1]
            int a = route[i], b = route[i+1];
            // points[a-1] -> points[b-1]
            // (4, 7) -> (1, 4)
            // 4 7
            // 3 7
            // 2 7
            // 1 7
            // 1 6
            // 1 5
            // 1 4
            int x1 = points[a-1][0], y1 = points[a-1][1];
            int x2 = points[b-1][0], y2 = points[b-1][1];
            // (x1, y1) -> (x2, y2)
            if (i == 0) {
                if (check[x1][y1][t] < 2) {
                    check[x1][y1][t]++;
                    if (check[x1][y1][t] == 2) ans++;
                }
                t++;    
            }
            if (x1 < x2) {
                for (int j = x1+1; j <= x2; ++j, ++t) {
                    if (check[j][y1][t] == 2) continue;
                    check[j][y1][t]++;
                    if (check[j][y1][t] == 2) ans++;
                }
            } else if (x1 > x2) {
                for (int j = x1-1; j >= x2; --j, ++t) {
                    if (check[j][y1][t] == 2) continue;
                    check[j][y1][t]++;
                    if (check[j][y1][t] == 2) ans++;
                }
            }
            if (y1 < y2) {
                for (int j = y1+1; j <= y2; ++j, ++t) {
                    if (check[x2][j][t] == 2) continue;
                    check[x2][j][t]++;
                    if (check[x2][j][t] == 2) ans++;
                }
            } else if (y1 > y2) {
                for (int j = y1-1; j >= y2; --j, ++t) {
                    if (check[x2][j][t] == 2) continue;
                    check[x2][j][t]++;
                    if (check[x2][j][t] == 2) ans++;
                }
            }
            
        }
    }
    return ans;
}