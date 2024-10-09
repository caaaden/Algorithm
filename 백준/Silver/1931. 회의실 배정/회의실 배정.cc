#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define all(v) v.begin(), v.end()
#define X first
#define Y second
using namespace std;
using pii = pair<int, int>;

int main() {
    fastio;

    int n;
    cin >> n;
    vector<pii> v(n);
    for (auto& [a, b] : v) cin >> a >> b;
    sort(all(v), [](const pii& a, const pii& b) {
        if (a.Y == b.Y) return a.X < b.X;
        return a.Y < b.Y;
    });
    int cnt = 1;
    int end = v[0].Y;
    for (int i = 1; i < n; ++i) {
        if (v[i].X < end) continue;
        cnt++;
        end = v[i].Y;
    }
    cout << cnt;
}