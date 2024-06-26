#include <bits/stdc++.h>

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
using pii = pair<int, int>;

int n, m, d;
vector<vector<int>> board;
int dx[] = {0, -1, 0};
int dy[] = {-1, 0, 1};

int bfs(vector<int>& cols) {
    vector<vector<int>> tmpBoard = board;
    int cnt = 0;
    for (int i = n; i >= 1; --i) {
        set<pii> st;
        for (int j = 0; j < 3; ++j) {
            // i, cols[j]
            queue<pii> Q;
            Q.push({i, cols[j]});
            vector<vector<int>> dist(n+1, vector<int>(m+1)); // 0 : 미방문
            dist[i][cols[j]] = 1;
            // 왼쪽, 위, 오른쪽순으로 bfs
            // 탐색 중 1이 발견되면 set에 삽입하고 중단,
            // 거리가 d를 넘어가면 탐색을 중단한다.
            while (Q.size()) {
                int nowX = Q.front().first;
                int nowY = Q.front().second;
                Q.pop();
                if (tmpBoard[nowX][nowY]) {
                    st.insert({nowX, nowY});
                    break;
                }
                if (dist[nowX][nowY] == d) continue; // 거리가 d가 될 때 더이상 다음으로 넘어가지 않음
                for (int k = 0; k < 3; ++k) {
                    int nextX = nowX + dx[k];
                    int nextY = nowY + dy[k];
                    if (nextX < 1 || nextX > n || nextY < 1 || nextY > m) continue;
                    if (dist[nextX][nextY]) continue;
                    dist[nextX][nextY] = dist[nowX][nowY] + 1;
                    Q.push({nextX, nextY});
                }
            }
        }
        cnt += st.size();
        for (auto& [a, b] : st) {
            tmpBoard[a][b] = 0;
        }
    }
    return cnt;
}

int main() {
    fastio;


    cin >> n >> m >> d;
    board.resize(n+1, vector<int>(m+1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> board[i][j];
        }
    }
    // m개의 열 중 3개 고르기
    int ans = 0;
    for (int i = 1; i <= m-2; ++i) {
        for (int j = i+1; j <= m-1; ++j) {
            for (int k = j+1; k <= m; ++k) {
                vector<int> cols = {i, j, k};
                ans = max(ans, bfs(cols));
            }
        }
    }
    cout << ans;
}