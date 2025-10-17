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
#define pb push_back
#define endl '\n'

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

//template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T, typename Compare = less<T>>
using ordered_set = tree<T, null_type, Compare, rb_tree_tag, tree_order_statistics_node_update>;

constexpr int dx[4] = {1, -1, 0, 0};
constexpr int dy[4] = {0, 0, 1, -1};
constexpr int dx2[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
constexpr int dy2[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
constexpr int bit = 9;
const long long MOD = 1e9 + 7;
const long long MOD2 = 1e9 + 9;
const int MAX = 1e9;

int main(){
    fastio;

    // 4x4 board를 숫자로 16bits 숫자로 표현
    // 숫자로 방문 표시 및 거리 표시
    // 큐에도 숫자로 삽입 및 pop
    // 상태 변환 시에만 board로 변환 후 가능한 이동 경우의 수를 모두 확인
    // vector<vector<bool>> board
    // int b
    vector<vector<bool>> s(4, vector<bool>(4));
    vector<vector<bool>> e(4, vector<bool>(4));
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            char c; cin >> c;
            s[i][j] = c - '0';
        }
    }
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            char c; cin >> c;
            e[i][j] = c - '0';
        }
    }
    // boardToNumber : 보드 -> 숫자 변환
    // boardToNumber(vector<vector<bool>>& b)
    auto boardToNumber = [](vector<vector<bool>>& b) {
        int ret = 0;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                ret |= b[i][j];
                ret <<= 1;
            }
        }
        ret >>= 1;
        return ret;
    };

    auto numberToBoard = [](int x) {
        vector<vector<bool>> ret(4, vector<bool>(4));
        for (int i = 3; i >= 0; --i) {
            for (int j = 3; j >= 0; --j) {
                // x & 1
                ret[i][j] = x & 1;
                x >>= 1;
            }
        }
        return ret;
    };

    vector<int> dist(100000, -1);
    dist[boardToNumber(s)] = 0;
    // queue<int> Q;
    queue<int> Q;
    Q.push(boardToNumber(s));
    while (Q.size()) {
        vector<vector<bool>> nowB = numberToBoard(Q.front());
        Q.pop();
        if (nowB == e) {
            cout << dist[boardToNumber(e)];
            return 0;
        }
        // nowB[i][j] == true인 (i, j)에 대해
        // 이동할 수 있는 모든 곳
        // 범위를 벗어날 경우 : continue
        // 이미 다른 1이 있을 경우 : continue
        // 이미 방문한 경우 : continue
        // dist + 1, Q.push
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                if (!nowB[i][j]) continue;
                for (int dir = 0; dir < 8; ++dir) {
                    int nx = i + dx2[dir];
                    int ny = j + dy2[dir];
                    // 0...3
                    if (nx < 0 || nx > 3 || ny < 0 || ny > 3) continue;
                    if (nowB[nx][ny]) continue;
                    // (i, j) -> (nx, ny)
                    // swap(nowB[i][j], nowB[nx][ny])
                    // nowB[i][j] = 0, nowB[nx][ny] = 1
                    // dist[boardToNumber(nowB)] != -1
                    vector<vector<bool>> nextB = nowB;
                    swap(nextB[i][j], nextB[nx][ny]);
                    if (dist[boardToNumber(nextB)] != -1) continue;
                    dist[boardToNumber(nextB)] = dist[boardToNumber(nowB)] + 1;
                    Q.push(boardToNumber(nextB));
                }
            }
        }
    }
}