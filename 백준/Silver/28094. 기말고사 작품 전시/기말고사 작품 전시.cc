#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> score(n+1, vector<int>(n+1));
        for (int i = 0; i < m; ++i) {
            int v, a, b;
            cin >> v >> a >> b;
            score[a][b] += v;
        }
        vector<int> order(n);
        for (int i = 0; i < n; ++i) {
            order[i] = i+1;
        }
        int maxScore = 0;
        int cnt = 1;
        do {
            int totalScore = 0;
            for (int i = 0; i < n-1; ++i) {
                for (int j = i+1; j < n; ++j) {
                    totalScore += score[order[i]][order[j]];
                }
            }
            if (totalScore > maxScore) {
                maxScore = totalScore;
                cnt = 1;
            } else if (totalScore == maxScore) {
                cnt++;
            }
        } while (next_permutation(order.begin(), order.end()));
        cout << maxScore << ' ' << cnt << '\n';
    }
}