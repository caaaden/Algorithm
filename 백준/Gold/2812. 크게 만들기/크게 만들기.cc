#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using pii = pair<int, int>;

struct cmp {
    bool operator() (const pii& a, const pii& b) {
        if (a.first == b.first) return a.second > b.second;
        else return a.first < b.first;
    }
};

int main() {
    fastio;

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    priority_queue<pii, vector<pii>, cmp> pq;
    int prev = 0;
    int next;
    vector<int> ans;
    for (int i = 0; i < k+1; ++i) pq.push({s[i] - '0', i});
    int tmp = k+1;
    while (k > 0) {
        while (pq.top().second < prev) pq.pop();
        int val = pq.top().first;
        next = pq.top().second;
        k -= (next - prev);
        ans.push_back(val);
        prev = next + 1;
        if (k == 0) {
            for (int i = tmp; i < n; ++i) ans.push_back(s[i] - '0');
            break;
        }
        if (tmp == n) break;
        pq.push({s[tmp] - '0', tmp});
        tmp++;
    }
    for (auto e : ans) cout << e;
}