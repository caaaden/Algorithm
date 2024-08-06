#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int ans, score;
int rightAns[10];
int myAns[10];
void dfs(int k) {
    if (10-k+score < 5) return;
    if (k == 10) {
        if (score >= 5) ans++;
        return;
    }
    if (k < 2) {
        for (int i = 1; i <= 5; ++i) {
            if (rightAns[k] == i) score++;
            myAns[k] = i;
            dfs(k+1);
            if (rightAns[k] == i) score--;
        }
    } else {
        for (int i = 1; i <= 5; ++i) {
            if (myAns[k-2] == myAns[k-1] && myAns[k-1] == i) continue;
            if (rightAns[k] == i) score++;
            myAns[k] = i;
            dfs(k+1);
            if (rightAns[k] == i) score--;
        }
    }
}
int main() {
    fastio;

    for (auto& e : rightAns) cin >> e;
    dfs(0);
    cout << ans;
}