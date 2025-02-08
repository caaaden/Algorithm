#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

#define fastio ios::sync_with_stdio(0), cin.tie(0)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define X first
#define Y second
#define rep(i, a, b) for (int i = a; i < b; ++i)

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using psi = pair<string, int>;
using piii = pair<int, pii>;
using piiii = pair<pii, pii>;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

constexpr int dx[4] = {1, -1, 0, 0};
constexpr int dy[4] = {0, 0, 1, -1};
constexpr int bit = 9;
const long long MOD = 1e9 + 7;

int main(){
    fastio;

    vector<vector<int>> board(501, vector<int>(501));
    auto getMinAndMaxCoords = [](int x1, int y1, int x2, int y2) {
        int minX = min(x1, x2);
        int maxX = max(x1, x2);
        int minY = min(y1, y2);
        int maxY = max(y1, y2);
        return make_tuple(minX, minY, maxX, maxY);
    };

    int n;
    cin >> n;    
    for (int i = 0; i < n; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        auto [minX, minY, maxX, maxY] = getMinAndMaxCoords(x1, y1, x2, y2);
        for (int j = minX; j <= maxX; ++j) {
            for (int k = minY; k <= maxY; ++k) {
                board[j][k] = 1;
            }
        }
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        auto [minX, minY, maxX, maxY] = getMinAndMaxCoords(x1, y1, x2, y2);
        for (int j = minX; j <= maxX; ++j) {
            for (int k = minY; k <= maxY; ++k) {
                board[j][k] = 2;
            }
        }
    }
    vector<vector<int>> dist(501, vector<int>(501, -1));
    dist[0][0] = 0;
    deque<pii> DQ;
    DQ.push_back({0, 0});
    while (DQ.size()) {
        int nowX = DQ.front().X;
        int nowY = DQ.front().Y;
        DQ.pop_front();
        if (nowX == 500 && nowY == 500) {
            cout << dist[nowX][nowY];
            return 0;
        }
        for (int i = 0; i < 4; ++i) {
            int nextX = nowX + dx[i];
            int nextY = nowY + dy[i];
            if (nextX < 0 || nextX > 500 || nextY < 0 || nextY > 500) continue;
            if (board[nextX][nextY] == 2) continue;
            if (dist[nextX][nextY] != -1) continue;
            if (board[nextX][nextY]) {
                DQ.push_back({nextX, nextY});
                dist[nextX][nextY] = dist[nowX][nowY] + 1;
            } else {
                DQ.push_front({nextX, nextY});
                dist[nextX][nextY] = dist[nowX][nowY];
            }
        }
    }
    cout << -1;
}