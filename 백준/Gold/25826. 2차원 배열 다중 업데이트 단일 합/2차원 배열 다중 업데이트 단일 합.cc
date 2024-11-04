#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;

struct Query {
    int x1, y1, x2, y2;
    ll k;
};

int main() {
    fastio;

    int n, m;
    cin >> n >> m;
    vector<vector<int>> board(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> board[i][j];
        }
    }
    vector<Query> v(m-1);
    int tmp;
    for (auto& e : v) {
        cin >> tmp >> e.x1 >> e.y1 >> e.x2 >> e.y2 >> e.k;
    }
    int sx, sy, ex, ey;
    cin >> tmp >> sx >> sy >> ex >> ey;
    ll ans = 0;
    for (int i = sx; i <= ex; ++i) {
        for (int j = sy; j <= ey; ++j) {
            ans += board[i][j];
        }
    }
    for (auto& e : v) {
        int a = max(sx, e.x1);
        int b = min(ex, e.x2);
        int c = max(sy, e.y1);
        int d = min(ey, e.y2);
        if (a <= b && c <= d) {
            ans += (b - a + 1) * (d - c + 1) * e.k;
        }
    }
    cout << ans;
}