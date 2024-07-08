#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int n;
int ans = 2;
void move(vector<vector<int>>& board, int k) {
    if (k == 5) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                ans = max(ans, board[i][j]);
            }
        }
        return;
    }
    vector<vector<int>> newBoard(n+1, vector<int>(n+1));
    for (int i = 1; i <= n; ++i) {
        stack<int> st;
        for (int j = 1; j <= n; ++j) {
            if (board[j][i] == 0) continue;
            st.push(board[j][i]);
        }
        queue<int> Q;
        while (st.size()) {
            if (st.size() == 1) {
                Q.push(st.top());
                st.pop();
            } else {
                int x = st.top(); st.pop();
                if (st.top() == x) {
                    st.pop();
                    Q.push(x*2);
                } else Q.push(x);
            }
        }
        for (int j = n; Q.size() && j >= 1; --j, Q.pop()) newBoard[j][i] = Q.front();
    }
    move(newBoard, k+1);
    newBoard.clear();
    newBoard.resize(n+1, vector<int>(n+1));
    for (int i = 1; i <= n; ++i) {
        stack<int> st;
        for (int j = n; j >= 1; --j) {
            if (board[j][i] == 0) continue;
            st.push(board[j][i]);
        }
        queue<int> Q;
        while (st.size()) {
            if (st.size() == 1) {
                Q.push(st.top());
                st.pop();
            } else {
                int x = st.top(); st.pop();
                if (st.top() == x) {
                    st.pop();
                    Q.push(x*2);
                } else Q.push(x);
            }
        }
        for (int j = 1; Q.size() && j <= n; ++j, Q.pop()) newBoard[j][i] = Q.front();
    }
    move(newBoard, k+1);
    newBoard.clear();
    newBoard.resize(n+1, vector<int>(n+1));
    for (int i = 1; i <= n; ++i) {
        stack<int> st;
        for (int j = 1; j <= n; ++j) {
            if (board[i][j] == 0) continue;
            st.push(board[i][j]);
        }
        queue<int> Q;
        while (st.size()) {
            if (st.size() == 1) {
                Q.push(st.top());
                st.pop();
            } else {
                int x = st.top(); st.pop();
                if (st.top() == x) {
                    st.pop();
                    Q.push(x*2);
                } else Q.push(x);
            }
        }
        for (int j = n; Q.size() && j >= 1; --j, Q.pop()) newBoard[i][j] = Q.front();
    }
    move(newBoard, k+1);
    newBoard.clear();
    newBoard.resize(n+1, vector<int>(n+1));
    for (int i = 1; i <= n; ++i) {
        stack<int> st;
        for (int j = n; j >= 1; --j) {
            if (board[i][j] == 0) continue;
            st.push(board[i][j]);
        }
        queue<int> Q;
        while (st.size()) {
            if (st.size() == 1) {
                Q.push(st.top());
                st.pop();
            } else {
                int x = st.top(); st.pop();
                if (st.top() == x) {
                    st.pop();
                    Q.push(x*2);
                } else Q.push(x);
            }
        }
        for (int j = 1; Q.size() && j <= n; ++j, Q.pop()) newBoard[i][j] = Q.front();
    }
    move(newBoard, k+1);
}

int main() {
    fastio;

    cin >> n;
    vector<vector<int>> board(n+1, vector<int>(n+1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> board[i][j];
        }
    }
    move(board, 0);
    cout << ans;
}