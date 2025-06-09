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

const int N = 9;
const int BOX_SIZE = 3;
vector<vector<int>> board(N, vector<int>(N));

// 특정 위치 (row, col)에 num을 놓는 것이 안전한지 확인
inline bool is_safe(int r, int c, int num) {
    // 행 검사
    for (int col_idx = 0; col_idx < N; ++col_idx) {
        if (board[r][col_idx] == num) return false;
    }
    // 열 검사
    for (int row_idx = 0; row_idx < N; ++row_idx) {
        if (board[row_idx][c] == num) return false;
    }
    // 3x3 박스 검사
    int start_row = r - r % BOX_SIZE;
    int start_col = c - c % BOX_SIZE;
    for (int i = 0; i < BOX_SIZE; ++i) {
        for (int j = 0; j < BOX_SIZE; ++j) {
            if (board[start_row + i][start_col + j] == num) return false;
        }
    }
    return true;
}

// 명백한 칸들을 채우는 함수 (Naked & Hidden Singles)
// 반환값: true면 계속 진행 가능, false면 모순 발생
bool fill_obvious_cells() {
    bool changed_in_iteration;
    do {
        changed_in_iteration = false;

        // 1. Naked Singles
        for (int r = 0; r < N; ++r) {
            for (int c = 0; c < N; ++c) {
                if (board[r][c] == 0) {
                    int possible_count = 0;
                    int last_possible_num = 0;
                    for (int num_to_try = 1; num_to_try <= N; ++num_to_try) {
                        if (is_safe(r, c, num_to_try)) {
                            possible_count++;
                            last_possible_num = num_to_try;
                        }
                    }
                    if (possible_count == 0) return false; // 모순: 빈 칸에 들어갈 숫자가 없음
                    if (possible_count == 1) {
                        // is_safe는 이미 위에서 last_possible_num에 대해 통과했으므로 재확인 불필요
                        board[r][c] = last_possible_num;
                        changed_in_iteration = true;
                    }
                }
            }
        }

        // 2. Hidden Singles
        // 행 기준
        for (int r = 0; r < N; ++r) {
            for (int num_to_find = 1; num_to_find <= N; ++num_to_find) {
                bool num_present_in_row = false;
                for(int c_check = 0; c_check < N; ++c_check) if(board[r][c_check] == num_to_find) {num_present_in_row = true; break;}
                if(num_present_in_row) continue; // 이미 숫자가 행에 있으면 Hidden Single 대상 아님

                int possible_cell_count = 0;
                int last_possible_col = -1;
                for (int c = 0; c < N; ++c) {
                    if (board[r][c] == 0 && is_safe(r, c, num_to_find)) {
                        possible_cell_count++;
                        last_possible_col = c;
                    }
                }
                if (possible_cell_count == 1) {
                    // board[r][last_possible_col]는 0이어야 함 (위의 if board[r][c] == 0 조건)
                    // is_safe는 이미 위에서 통과했으므로 재확인 불필요
                    board[r][last_possible_col] = num_to_find;
                    changed_in_iteration = true;
                }
                    // 만약 num_present_in_row == false 인데 possible_cell_count == 0 이면 모순임
                else if (possible_cell_count == 0 && !num_present_in_row) {
                    return false;
                }
            }
        }

        // 열 기준
        for (int c = 0; c < N; ++c) {
            for (int num_to_find = 1; num_to_find <= N; ++num_to_find) {
                bool num_present_in_col = false;
                for(int r_check = 0; r_check < N; ++r_check) if(board[r_check][c] == num_to_find) {num_present_in_col = true; break;}
                if(num_present_in_col) continue;

                int possible_cell_count = 0;
                int last_possible_row = -1;
                for (int r = 0; r < N; ++r) {
                    if (board[r][c] == 0 && is_safe(r, c, num_to_find)) {
                        possible_cell_count++;
                        last_possible_row = r;
                    }
                }
                if (possible_cell_count == 1) {
                    board[last_possible_row][c] = num_to_find;
                    changed_in_iteration = true;
                }
                else if (possible_cell_count == 0 && !num_present_in_col) {
                    return false;
                }
            }
        }

        // 박스 기준
        for (int box_idx = 0; box_idx < N; ++box_idx) { // 0~8번 박스
            int start_row = (box_idx / BOX_SIZE) * BOX_SIZE;
            int start_col = (box_idx % BOX_SIZE) * BOX_SIZE;
            for (int num_to_find = 1; num_to_find <= N; ++num_to_find) {
                bool num_present_in_box = false;
                for(int i=0; i<BOX_SIZE; ++i) for(int j=0; j<BOX_SIZE; ++j) if(board[start_row+i][start_col+j] == num_to_find) {num_present_in_box = true; break;}
                if(num_present_in_box) continue;

                int possible_cell_count = 0;
                pair<int, int> last_possible_cell = {-1, -1};
                for (int i = 0; i < BOX_SIZE; ++i) {
                    for (int j = 0; j < BOX_SIZE; ++j) {
                        int cur_r = start_row + i;
                        int cur_c = start_col + j;
                        if (board[cur_r][cur_c] == 0 && is_safe(cur_r, cur_c, num_to_find)) {
                            possible_cell_count++;
                            last_possible_cell = {cur_r, cur_c};
                        }
                    }
                }
                if (possible_cell_count == 1) {
                    board[last_possible_cell.first][last_possible_cell.second] = num_to_find;
                    changed_in_iteration = true;
                }
                else if (possible_cell_count == 0 && !num_present_in_box) {
                    return false;
                }
            }
        }
    } while (changed_in_iteration); // 변경이 없을 때까지 반복
    return true; // 모순 없이 종료
}


// 다음 빈 칸을 찾는 함수 (MRV 없이, 순차적으로 탐색)
optional<pair<int, int>> find_empty_simple() {
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            if (board[r][c] == 0) {
                return {{r, c}};
            }
        }
    }
    return nullopt;
}

// 주 스도쿠 해결 함수
bool solve() {
    // 1. 제약 전파를 통해 명백한 칸들을 먼저 채운다.
    // fill_obvious_cells 내부에서 board가 직접 수정됨.
    // 이 함수가 false를 반환하면, 현재 board 상태가 모순임을 의미.
    if (!fill_obvious_cells()) {
        return false;
    }

    // 2. 빈 칸을 찾는다.
    optional<pair<int, int>> empty_loc = find_empty_simple();

    if (!empty_loc) { // 빈 칸이 없으면 해결 완료
        return true;
    }

    int r = empty_loc->first;
    int c = empty_loc->second;

    // 3. 백트래킹: 빈 칸에 숫자를 시도한다.
    for (int num_to_try = 1; num_to_try <= N; ++num_to_try) {
        if (is_safe(r, c, num_to_try)) {
            // 현재 board 상태를 백업. fill_obvious_cells가 여러 곳을 변경할 수 있으므로,
            // 간단히 board[r][c]=0 만으로는 이전 상태로 완벽히 돌아가지 못할 수 있음.
            vector<vector<int>> board_backup = board;

            board[r][c] = num_to_try;

            if (solve()) { // 재귀 호출
                return true;
            }

            board = board_backup; // 백트래킹: 이전 상태로 보드 전체를 복원
        }
    }
    return false; // 현재 칸에서 해결책 못 찾음
}

int main() {
    fastio;

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cin >> board[i][j];
        }
    }
    solve();
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
}