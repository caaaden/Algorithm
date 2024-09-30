#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int solution(int n, int k, vector<int> enemy) {
    if (enemy.size() <= k) return enemy.size();
    priority_queue<int, vector<int>, greater<int>> pq;
    ll sum = 0;
    for (int i = 0; i < enemy.size(); ++i) {
        pq.push(enemy[i]);
        if (pq.size() > k) {
            sum += pq.top();
            pq.pop();
        }
        if (sum > n) return i;
    }
    return enemy.size();
}