#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
using pii = pair<int, int>;

int board[101][101];
int main() {
    fastio;

    int r, c, k;
    cin >> r >> c >> k;
    int n = 3, m = 3;
    for (int i = 1; i <= 3; ++i) {
        for (int j = 1; j <= 3; ++j) {
            cin >> board[i][j];
        }
    }
    for (int t = 0; t <= 100; ++t) {
        if (board[r][c] == k) {
            cout << t;
            return 0;
        }
        if (n >= m) {
            int nextM = 0;
            for (int i = 1; i <= n; ++i) {
                unordered_map<int, int> mp;
                for (int j = 1; j <= m; ++j) {
                    if (!board[i][j]) continue;
                    mp[board[i][j]]++;
                }
                vector<pii> v;
                v.reserve(mp.size());
                for (auto& e : mp) v.push_back(e);
                sort(v.begin(), v.end(), [](const pii& a, const pii& b) {
                    if (a.second == b.second) return a.first < b.first;
                    return a.second < b.second;
                });
                nextM = max(nextM, min((int)v.size(), 50)*2);
                for (int j = 0; j < min((int)v.size(), 50); ++j) {
                    board[i][j*2+1] = v[j].first;
                    board[i][j*2+2] = v[j].second;
                }
                for (int j = v.size(); j < 50; ++j) {
                    board[i][j*2+1] = 0;
                    board[i][j*2+2] = 0;
                }
            }
            m = nextM;
        } else {
            int nextN = 0;
            for (int i = 1; i <= m; ++i) {
                unordered_map<int, int> mp;
                for (int j = 1; j <= n; ++j) {
                    if (!board[j][i]) continue;
                    mp[board[j][i]]++;
                }
                vector<pii> v;
                v.reserve(mp.size());
                for (auto& e : mp) v.push_back(e);
                sort(v.begin(), v.end(), [](const pii& a, const pii& b) {
                    if (a.second == b.second) return a.first < b.first;
                    return a.second < b.second;
                });
                nextN = max(nextN, min((int)v.size(), 50)*2);
                for (int j = 0; j < min((int)v.size(), 50); ++j) {
                    board[j*2+1][i] = v[j].first;
                    board[j*2+2][i] = v[j].second;
                }
                for (int j = v.size(); j < 50; ++j) {
                    board[j*2+1][i] = 0;
                    board[j*2+2][i] = 0;
                }
            }
            n = nextN;
        }
    }
    cout << -1;
}