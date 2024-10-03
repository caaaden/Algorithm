#include <bits/stdc++.h>
using namespace std;

int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};
bool check(vector<string>& place, int x, int y) {
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx > 4 || ny < 0 || ny > 4) continue;
        if (place[nx][ny] == 'P') return false;
    }
    
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i]*2;
        int ny = y + dy[i]*2;
        if (nx < 0 || nx > 4 || ny < 0 || ny > 4) continue;
        if (place[nx][ny] == 'P') {
            int mx = x + dx[i];
            int my = y + dy[i];
            if (place[mx][my] == 'O') return false;
        }
    }
    
    for (int i = 4; i < 8; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx > 4 || ny < 0 || ny > 4) continue;
        if (place[nx][ny] == 'P') {
            if (place[x+dx[i]][y] == 'O') return false;
            if (place[x][y+dy[i]] == 'O') return false;
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> ans;
    ans.reserve(5);
    for (auto& place : places) {
        bool flag = true;
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                if (place[i][j] != 'P') continue;
                if (check(place, i, j)) continue;
                flag = false;
                break;
            }
            if (!flag) break;
        }
        ans.push_back(flag);
    }
    return ans;
}