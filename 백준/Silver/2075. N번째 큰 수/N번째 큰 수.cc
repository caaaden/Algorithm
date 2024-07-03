#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
using pii = pair<int, int>;

int main() {
    fastio;

    int n;
    cin >> n;
    vector<stack<int>> v(n);
    priority_queue<pii> pq;
    for (int i = 0; i < n; ++i) {
        for (int j = 0, x; j < n; ++j) {
            cin >> x;
            if (i == n-1) {
                pq.push({x, j});
            } else {
                v[j].push(x);
            }
        }
    }
    for (int i = 0; i < n-1; ++i) {
        int col = pq.top().second;
        pq.pop();
        pq.push({v[col].top(), col});
        v[col].pop();
    }
    cout << pq.top().first;
}
