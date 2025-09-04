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
const int MAX = 1e9;

int main(){
    fastio;

    int n, b, k;
    cin >> n >> b >> k;
    vector<vector<int>> board(n+1, vector<int>(n+1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> board[i][j];
        }
    }
    vector<priority_queue<pii>> pqs(n+1);
    vector<priority_queue<pii, vector<pii>, greater<pii>>> pqs2(n+1);
    vector<vector<int>> mx(n-b+2, vector<int>(n-b+2));
    vector<vector<int>> mn(n-b+2, vector<int>(n-b+2));

    auto init = [&]() {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= b; ++j) {
                pqs[i].push({board[i][j], j});
            }
        }
        priority_queue<pii> pq;
        for (int i = 1; i <= b; ++i) {
            pq.push({pqs[i].top().X, i});
        }
        mx[1][1] = pq.top().X;
        for (int i = 1; i <= n-b; ++i) {
            while (pq.top().Y <= i) pq.pop();
            pq.push({pqs[b+i].top().X, b+i});
            mx[i+1][1] = pq.top().X;
        }
    };

    auto init2 = [&]() {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= b; ++j) {
                pqs2[i].push({board[i][j], j});
            }
        }
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        for (int i = 1; i <= b; ++i) {
            pq.push({pqs2[i].top().X, i});
        }
        mn[1][1] = pq.top().X;
        for (int i = 1; i <= n-b; ++i) {
            while (pq.top().Y <= i) pq.pop();
            pq.push({pqs2[b+i].top().X, b+i});
            mn[i+1][1] = pq.top().X;
        }
    };

    auto update = [&]() {
        for (int i = 1; i <= n-b; ++i) {
            for (int j = 1; j <= n; ++j) {
                while (pqs[j].top().Y <= i) pqs[j].pop();
                pqs[j].push({board[j][b+i], b+i});
            }
            priority_queue<pii> pq;
            for (int j = 1; j <= b; ++j) {
                pq.push({pqs[j].top().X, j});
            }
            mx[1][i+1] = pq.top().X;
            for (int j = 1; j <= n-b; ++j) {
                while (pq.top().Y <= j) pq.pop();
                pq.push({pqs[b+j].top().X, b+j});
                mx[j+1][i+1] = pq.top().X;
            }
        }
    };

    auto update2 = [&]() {
        for (int i = 1; i <= n-b; ++i) {
            for (int j = 1; j <= n; ++j) {
                while (pqs2[j].top().Y <= i) pqs2[j].pop();
                pqs2[j].push({board[j][b+i], b+i});
            }
            priority_queue<pii, vector<pii>, greater<pii>> pq;
            for (int j = 1; j <= b; ++j) {
                pq.push({pqs2[j].top().X, j});
            }
            mn[1][i+1] = pq.top().X;
            for (int j = 1; j <= n-b; ++j) {
                while (pq.top().Y <= j) pq.pop();
                pq.push({pqs2[b+j].top().X, b+j});
                mn[j+1][i+1] = pq.top().X;
            }
        }
    };

    init();
    init2();
    update();
    update2();

    while (k--) {
        int i, j; cin >> i >> j;
        cout << mx[i][j] - mn[i][j] << '\n';
    }
}