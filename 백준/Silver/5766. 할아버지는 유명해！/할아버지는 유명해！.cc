#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
using pii = pair<int, int>;

int main() {
    fastio;

    while (true) {
        int n, m;
        cin >> n >> m;
        if (!n && !m) break;
        vector<int> point(10001);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int x;
                cin >> x;
                point[x]++;
            }
        }
        vector<pii> score;
        for (int i = 1; i <= 10000; ++i) {
            if (!point[i]) continue;
            score.push_back({i, point[i]});
        }
        sort(score.begin(), score.end(), [](const pii& a, const pii& b) {
            if (a.second == b.second) return a.first < b.first;
            return a.second > b.second;
        });
        cout << score[1].first << ' ';
        for (int i = 2; i < score.size(); ++i) {
            if (score[i].second != score[i-1].second) break;
            cout << score[i].first << ' ';
        }
        cout << '\n';
    }
}