#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (i & 1) {
            minHeap.push(x);
        } else {
            maxHeap.push(x);
        }
        if (i > 0 && maxHeap.top() > minHeap.top()) {
            int tmp1 = maxHeap.top(); maxHeap.pop();
            int tmp2 = minHeap.top(); minHeap.pop();
            maxHeap.push(tmp2);
            minHeap.push(tmp1);
        }
        cout << maxHeap.top() << '\n';
    }
}