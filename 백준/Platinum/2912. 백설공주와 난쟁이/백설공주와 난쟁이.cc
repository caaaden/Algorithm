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
using piiii = pair<pii, pii>;

int main() {
    fastio;

    random_device rd;
    mt19937 mt(rd());

    int n, c;
    cin >> n >> c;
    vector<int> v(n+1);
//    vector<int> indices[10001]; // 어떤 숫자의 인덱스들
    vector<vector<int>> indices(c+1);
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
//        if (indices[v[i]].empty()) indices[v[i]].push_back(-1); // 검색 편의를 위해 삽입
        indices[v[i]].push_back(i);
    }
    int m;
    cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r;
        // l...r 에서 랜덤으로 하나 고르기, 그걸 100번했을 때 과반이 있다면 걸리지 않을 확률 1/2^100
        uniform_int_distribution<int> dis(l, r);
        // dis(mt)
        // indices, l, r
        int found = -1;
        for (int i = 0; i < 100; ++i) {
            int idx = dis(mt);
            int val = v[idx];
            // indices[val]
            int cnt = upper_bound(all(indices[val]), r) - lower_bound(all(indices[val]), l);
            if (cnt > (r - l + 1) / 2) {
                found = val;
                break;
            }
        }
        if (found != -1) cout << "yes " << found << '\n';
        else cout << "no" << '\n';
    }
}