#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
using pii = pair<int, int>;

pii compress(int x, int y, int sz, vector<vector<int>>& board) {
    if (sz == 1) {
        if (board[x][y]) return {0, 1};
        return {1, 0};
    }
    int half = sz / 2;
    pii a = compress(x, y, half, board);
    pii b = compress(x, y+half, half, board);
    pii c = compress(x+half, y, half, board);
    pii d = compress(x+half, y+half, half, board);
    pii sum = {a.X+b.X+c.X+d.X, a.Y+b.Y+c.Y+d.Y};
    if (sum.X == 4 && sum.Y == 0) {
        return {1, 0};
    } else if (sum.X == 0 && sum.Y == 4) {
        return {0, 1};
    } else {
        return sum;
    }
}

vector<int> solution(vector<vector<int>> arr) {
    int n = arr.size();
    pii ans = compress(0, 0, n, arr);
    return {ans.first, ans.second};
}