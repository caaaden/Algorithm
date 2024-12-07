#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0);
#define all(v) v.begin(), v.end()
#define X first
#define Y second
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using piii = pair<int, pii>;

int main() {
    fastio;

    int n, l;
    cin >> n >> l;
    deque<pii> dq;
    for (int x, i = 0; i < n; ++i) {
        cin >> x;
        if (dq.size() && dq.front().Y + l <= i) dq.pop_front();
        while (dq.size() && dq.back().X >= x) dq.pop_back(); // monotonic increasing
        dq.push_back({x, i});
        cout << dq.front().X << ' ';
    }
}