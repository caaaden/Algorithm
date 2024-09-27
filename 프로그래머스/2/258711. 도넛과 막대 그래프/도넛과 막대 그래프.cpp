#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
using pii = pair<int, int>;

vector<int> solution(vector<vector<int>> edges) {
    vector<pii> nodes(1000001);
    for (auto& edge: edges) {
        nodes[edge[0]].X++; 
        nodes[edge[1]].Y++;
    }
    int total;
    int origin;
    int stick = 0, eight = 0;
    vector<int> res(4);
    for (int i = 1; i <= 1000000; ++i) {
        if (nodes[i].X >= 2 && !nodes[i].Y) {
            total = nodes[i].X;
            origin = i;
        }
        if (!nodes[i].X && nodes[i].Y >= 1) stick++;
        if (nodes[i].X == 2 && nodes[i].Y >= 2) eight++;
    }
    return {origin, total-eight-stick, stick, eight};
}