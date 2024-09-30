#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int solution(int n, int k, vector<int> enemy) {
    // 1. pq에 삽입
    // 2. pq.size() > k : pq.top()을 sum에 더하기, pq.pop()
    // 3. 위를 반복하다 sum이 n을 초과하면 그 직전까지의 길이가 res
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