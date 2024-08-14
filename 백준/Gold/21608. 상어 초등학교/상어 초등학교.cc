#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
using pii = pair<int, int>;
using piii = pair<pii, int>;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int main() {
    fastio;

    int n;
    cin >> n;
    vector<vector<int>> relationship(n*n, vector<int>(5));
    vector<vector<int>> tmp(n*n+1);
    for (int i = 0; i < n*n; ++i) {
        int num;
        for (int j = 0; j < 5; ++j) {
            cin >> relationship[i][j];
            if (j == 0) num = relationship[i][j];
            else tmp[num].push_back(relationship[i][j]);
        }
    }
    vector<vector<int>> board(n, vector<int>(n));
    for (auto& student : relationship) {
        vector<piii> filtered;
        int numOfStudentLiked = 0;
        auto isStudentWhoLiked = [](vector<int>& student, int& x) {
            for (int i = 1; i <= 4; ++i) if (x == student[i]) return true;
            return false;
        };
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j]) continue;
                int cnt = 0;
                int emptySpace = 0;
                for (int k = 0; k < 4; ++k) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if (x < 0 || x > n-1 || y < 0 || y > n-1) continue;
                    if (!board[x][y]) {
                        emptySpace++;
                        continue;
                    }
                    cnt += isStudentWhoLiked(student, board[x][y]);
                }
                if (cnt >= numOfStudentLiked) {
                    if (cnt > numOfStudentLiked) {
                        filtered.clear();
                        numOfStudentLiked = cnt;
                    }
                    filtered.push_back({{i, j}, emptySpace});
                }
            }
        }
        sort(filtered.begin(), filtered.end(), [](const piii& a, const piii& b) {
            if (a.second == b.second) {
                if (a.first.first == b.first.first) {
                    return a.first.second < b.first.second;
                } else return a.first.first < b.first.first;
            } else return a.second > b.second;
        });
        board[filtered[0].first.first][filtered[0].first.second] = student[0];
    }
    int totalSatisfaction = 0;
    auto isStudentWhoLiked = [](vector<int>& student, int& x) {
        for (int i = 0; i < 4; ++i) if (x == student[i]) return true;
        return false;
    };
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int cnt = 0;
            for (int k = 0; k < 4; ++k) {
                int x = i + dx[k];
                int y = j + dy[k];
                if (x < 0 || x > n-1 || y < 0 || y > n-1) continue;
                cnt += isStudentWhoLiked(tmp[board[i][j]], board[x][y]);
            }
            int satisfaction = 1;
            if (cnt > 0) {
                for (int k = 0; k < cnt-1; ++k) satisfaction *= 10;
                totalSatisfaction += satisfaction;
            }
        }
    }
    cout << totalSatisfaction;
}