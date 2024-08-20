#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main() {
    fastio;

    int n;
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> board[i][j];
        }
    }
    // 흑, 백 지역으로 나눠 개수를 각각 구하고 곱해서 출력
    // 대각선 인덱스 관리
    // n, n-1
    //
    int white = 0, black = 0; // 구역별 놓을 수 있는 최대 비숍 개수
    vector<int> diag1(2*n-1); // 왼쪽아래방향 대각선
    unordered_map<int, int> diag2; // 인덱스 음수 계산
    function<void(int, int)> dfs = [&](int k, int idx) {
        white = max(white, k);
        for (int i = idx; i < n*n; ++i) {
            int a = i / n;
            int b = i % n;
            if ((a+b) & 1) continue;
            if (!board[a][b]) continue;
            if (diag1[a+b]) continue;
            if (diag2[a-b]) continue;
            diag1[a+b] = 1;
            diag2[a-b] = 1;
            dfs(k+1, i+1);
            diag1[a+b] = 0;
            diag2[a-b] = 0;
        }
    };
    function<void(int, int)> dfs2 = [&](int k, int idx) {
        black = max(black, k);
        for (int i = idx; i < n*n; ++i) {
            int a = i / n;
            int b = i % n;
            if ((a+b) % 2 == 0) continue;
            if (!board[a][b]) continue;
            if (diag1[a+b]) continue;
            if (diag2[a-b]) continue;
            diag1[a+b] = 1;
            diag2[a-b] = 1;
            dfs2(k+1, i+1);
            diag1[a+b] = 0;
            diag2[a-b] = 0;
        }
    };
    dfs(0, 0);
    dfs2(0, 0);
    cout << white + black;
}