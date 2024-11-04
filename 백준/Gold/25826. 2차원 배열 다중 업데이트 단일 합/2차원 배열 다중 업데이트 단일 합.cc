#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;

int main() {
    fastio;

    int n, m;
    cin >> n >> m;
    vector<vector<ll>> board(n+1, vector<ll>(n+1));
    vector<vector<ll>> v(n+1, vector<ll>(n+1));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> board[i][j];
        }
    }
    int tmp;
    for (int i = 0; i < m-1; ++i) {
        cin >> tmp;
        int x1, y1, x2, y2, k;
        cin >> x1 >> y1 >> x2 >> y2 >> k;
        v[x1][y1] += k;
        v[x1][y2+1] -= k;
        v[x2+1][y1] -= k;
        v[x2+1][y2+1] += k;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            v[j][i] += v[j-1][i];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            v[i][j] += v[i][j-1];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            v[i][j] += board[i][j];
        }
    }
    cin >> tmp;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    ll ans = 0;
    for (int i = x1; i <= x2; ++i) {
        for (int j = y1; j <= y2; ++j) {
            ans += v[i][j];
        }
    }
    cout << ans;
}