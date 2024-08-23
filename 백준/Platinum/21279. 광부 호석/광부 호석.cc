#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
using pii = pair<int, int>;
using i64 = long long;

struct Mineral {
    int x, y, v;
};

int main() {
    fastio;

    int n, c;
    cin >> n >> c;
    vector<Mineral> v(n);
    set<int, greater<int>> tmp; // 중복 제거 및 내림차순 정렬
    for (int i = 0; i < n; ++i) {
        cin >> v[i].x >> v[i].y >> v[i].v;
        tmp.insert(v[i].y);
    }
    vector<int> standard; // y 기준
    for (auto& e : tmp) standard.push_back(e);
    sort(v.begin(), v.end(), [](const Mineral& a, const Mineral& b) {
        if (a.x == b.x) return a.y < b.y;
        return a.x < b.x;
    });
    // y 기준 max heap, v값도 함께 넣기
    priority_queue<pii> pq; // {y, v}
    i64 ans = 0;
    i64 sum = 0;
    int idx = 0; // v의 idx
    for (auto& st : standard) {
        while (pq.size() && pq.top().first > st) {
            sum -= pq.top().second;
            pq.pop();
        }
        // v[idx].x, y, v
        while (pq.size() < c && idx < n) {
            // v[idx].y <= st
            if (v[idx].y <= st) {
                pq.push({v[idx].y, v[idx].v});
                sum += v[idx].v;
            }
            idx++;
        }
        ans = max(ans, sum);
    }
    cout << ans;
}