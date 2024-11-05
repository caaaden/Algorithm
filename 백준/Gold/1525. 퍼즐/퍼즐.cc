#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0);
#define all(v) v.begin(), v.end()
#define X first
#define Y second
using namespace std;
using ll = long long;
using pli = pair<ll, int>;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int main() {
    fastio;

    auto compress = [&](vector<vector<int>>& board) {
        ll ret = 0;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                ret |= 1LL * board[i][j];
                ret <<= 4;
            }
        }
        return ret;
    };

    auto decompress = [&](ll x) {
        vector<vector<int>> v(3, vector<int>(3));
        for (int i = 2; i >= 0; --i) {
            for (int j = 2; j >= 0; --j) {
                x >>= 4;
                v[i][j] = x & 15;
            }
        }
        return v;
    };

    vector<vector<int>> target = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};
    queue<pli> Q;
    unordered_set<ll> vis;
    vector<vector<int>> board(3, vector<int>(3));
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> board[i][j];
        }
    }
    ll a = compress(board);
    Q.push({a, 0});
    vis.insert(a);
    while (Q.size()) {
        vector<vector<int>> now = decompress(Q.front().first);
        int dist = Q.front().second;
        Q.pop();
        if (now == target) {
            cout << dist;
            return 0;
        }
        bool flag = false;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (!now[i][j]) {
                    flag = true;
                    for (int k = 0; k < 4; ++k) {
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        if (nx < 0 || nx > 2 || ny < 0 || ny > 2) continue;
                        swap(now[i][j], now[nx][ny]);
                        ll compressed = compress(now);
                        swap(now[i][j], now[nx][ny]);
                        if (vis.count(compressed)) continue;
                        vis.insert(compressed);
                        Q.push({compressed, dist+1});
                    }
                    break;
                }
            }
            if (flag) break;
        }
    }
    cout << -1;
}