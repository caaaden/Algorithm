#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end());
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; ++i) {
        if (!pq.empty() && pq.top() <= v[i].first) pq.pop();
        pq.push(v[i].second);
    }
    cout << pq.size();
}