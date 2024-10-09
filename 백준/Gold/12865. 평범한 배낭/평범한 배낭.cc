#include <bits/stdc++.h>
using namespace std;

int w[101];
int v[101];
int dp[101][100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // Frational Knapsack - Greedy로 풀이 가능.
    // 그러나 일반 Kanpsack은 Greedy가 최적해 보장 X
    // 따라서 dynamic programming or backtracking으로 풀이.
    
    // i 번호, j 배낭 무게
    // 부분집합에 포함되지 않는 경우 DP[i-1][j]
    // 부분집합에 포함하는 경우 DP[i-1][j-W[i]] + V[i]
    
    int n, k;
    cin >> n >> k; // n개의 물건, 총 무게 K
    
    for (int i = 1; i <= n; ++i) {
        cin >> w[i] >> v[i]; // i번째 물건의 무게와 가치.
    }
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            if (j >= w[i]) dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + v[i]);
            else dp[i][j] = dp[i-1][j];
        }
    }
    
    cout << dp[n][k];
}