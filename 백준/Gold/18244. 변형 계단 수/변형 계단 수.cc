#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

#define fastio ios::sync_with_stdio(0), cin.tie(0);
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
const long long MOD = 1000000007;

int main(){
    fastio;
    
    int N;
    cin >> N;
    
    // N이 1이면 0~9까지 모든 한 자리 수를 센다.
    if(N == 1){
        cout << 10 << "\n";
        return 0;
    }
    
    // dp[i][d][dir][r] : 길이가 i인 수에서 마지막 자리가 d이고,
    // dir이 0이면 마지막 이동이 증가, 1이면 감소,
    // r은 해당 방향의 연속 횟수 (1 또는 2; 3번 이상은 안 됨)
    // 배열의 크기는 N+1 x 10 x 2 x 3 (r은 인덱스 0은 사용하지 않고 1,2만 사용)
    long long dp[101][10][2][3] = {0};
    
    // 길이가 1인 수에서 시작하여 길이 2로 확장하는 초기 상태
    for(int d = 0; d < 10; d++){
        if(d + 1 <= 9) {
            dp[2][d+1][0][1] = (dp[2][d+1][0][1] + 1) % MOD; // 증가 방향, 연속 횟수 1
        }
        if(d - 1 >= 0) {
            dp[2][d-1][1][1] = (dp[2][d-1][1][1] + 1) % MOD; // 감소 방향, 연속 횟수 1
        }
    }
    
    // 길이 2부터 N-1까지 DP 전이
    for(int i = 2; i < N; i++){
        for(int d = 0; d < 10; d++){
            for(int dir = 0; dir < 2; dir++){
                for(int r = 1; r <= 2; r++){
                    long long cur = dp[i][d][dir][r];
                    if(cur == 0) continue;
                    
                    if(dir == 0){ // 이전 이동이 증가
                        // 연속 증가: d+1로 이동 (연속 횟수가 2 미만이어야 함)
                        if(d + 1 <= 9 && r < 2){
                            dp[i+1][d+1][0][r+1] = (dp[i+1][d+1][0][r+1] + cur) % MOD;
                        }
                        // 방향 전환 (증가 → 감소): d-1이 유효하면 연속 횟수 1로 초기화
                        if(d - 1 >= 0){
                            dp[i+1][d-1][1][1] = (dp[i+1][d-1][1][1] + cur) % MOD;
                        }
                    } else { // 이전 이동이 감소
                        // 연속 감소: d-1로 이동 (연속 횟수가 2 미만이어야 함)
                        if(d - 1 >= 0 && r < 2){
                            dp[i+1][d-1][1][r+1] = (dp[i+1][d-1][1][r+1] + cur) % MOD;
                        }
                        // 방향 전환 (감소 → 증가): d+1이 유효하면 연속 횟수 1로 초기화
                        if(d + 1 <= 9){
                            dp[i+1][d+1][0][1] = (dp[i+1][d+1][0][1] + cur) % MOD;
                        }
                    }
                }
            }
        }
    }
    
    // 길이 N인 모든 상태의 합을 구함
    long long ans = 0;
    for(int d = 0; d < 10; d++){
        for(int dir = 0; dir < 2; dir++){
            for(int r = 1; r <= 2; r++){
                ans = (ans + dp[N][d][dir][r]) % MOD;
            }
        }
    }
    
    cout << ans << "\n";
    return 0;
}