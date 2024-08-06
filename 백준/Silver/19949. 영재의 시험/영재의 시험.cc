#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int ans, score;
array<int, 10> rightAnswers;
vector<int> myAnswers;
void dfs(int k) {
    if (10-k+score < 5) return;
    if (k == 10) {
        if (score >= 5) ans++;
        return;
    }
    if (k < 2) {
        for (int i = 1; i <= 5; ++i) {
            if (rightAnswers[k] == i) score++;
            myAnswers.push_back(i);
            dfs(k+1);
            if (rightAnswers[k] == i) score--;
            myAnswers.pop_back();
        }
    } else {
        for (int i = 1; i <= 5; ++i) {
            if (myAnswers[k-2] == myAnswers[k-1] && myAnswers[k-1] == i) continue;
            if (rightAnswers[k] == i) score++;
            myAnswers.push_back(i);
            dfs(k+1);
            if (rightAnswers[k] == i) score--;
            myAnswers.pop_back();
        }
    }
}
int main() {
    fastio;

    for (auto& e : rightAnswers) cin >> e;
    dfs(0);
    cout << ans;
}