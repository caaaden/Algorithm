#include <bits/stdc++.h>

#define fastio ios::sync_with_stdio(0), cin.tie(0);
#define all(v) v.begin(), v.end()
#define X first
#define Y second
#define rep(i, a, b) for (int i = a; i < b; ++i)

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using piii = pair<int, pii>;
using piiii = pair<pii, pii>;

constexpr int dx[4] = {1, -1, 0, 0};
constexpr int dy[4] = {0, 0, 1, -1};
constexpr int bit = 9;

int main() {
    fastio;

    int n, k;
    cin >> n >> k;
    vector<int> v(n+1);
    for (int i = 1; i <= n; ++i) cin >> v[i];
    int m;
    cin >> m;
    vector<piii> query(m);
    vector<int> ans(m);
    for (int i = 0; i < m; ++i) {
        int s, e;
        cin >> s >> e;
        query[i] = {i, {s, e}};
    }
    sort(all(query), [](const piii& a, const piii& b) {
        int aa = a.Y.X >> bit;
        int bb = b.Y.X >> bit;
        if (aa != bb) return aa < bb;
        return (aa & 1) ? a.Y.Y < b.Y.Y : a.Y.Y > b.Y.Y;
    });
    vector<list<int>> indices(k+1);
    int sq = sqrt(n);
    vector<int> count(n); // 각 숫자의 최대 인덱스 차이의 빈도, 0~n-1
    vector<int> bucket(sq+2);
    auto add = [&v, &indices, &count, &bucket, &sq](int idx, bool isLeft) {
        int val = v[idx];
        if (indices[val].size()) {
            int diff = indices[val].back() - indices[val].front();
            count[diff]--;
            bucket[diff/sq]--;
        }
        if (isLeft) indices[val].push_front(idx);
        else indices[val].push_back(idx);
        int diff = indices[val].back() - indices[val].front();
        count[diff]++;
        bucket[diff/sq]++;
    };
    auto remove = [&v, &indices, &count, &bucket, &sq](int idx, bool isLeft) {
        int val = v[idx];
        int diff = indices[val].back() - indices[val].front();
        count[diff]--;
        bucket[diff/sq]--;
        if (isLeft) indices[val].pop_front();
        else indices[val].pop_back();
        if (indices[val].size()) {
            diff = indices[val].back() - indices[val].front();
            count[diff]++;
            bucket[diff/sq]++;
        }
    };
    auto getAnswer = [&count, &bucket, &sq, &n]() {
        int i = sq + 1;
        while (!bucket[i]) --i;
        int j = min((i+1) * sq - 1, n-1);
        while (!count[j]) --j;
        return j;
    };
    int s = query[0].Y.X, e = s - 1;
    for (int i = 0; i < m; ++i) {
        const int qs = query[i].Y.X;
        const int qe = query[i].Y.Y;
        while (e < qe) add(++e, false);
        while (s > qs) add(--s, true);
        while (e > qe) remove(e--, false);
        while (s < qs) remove(s++, true);
        ans[query[i].X] = getAnswer();
    }
    for (const auto& e : ans) cout << e << '\n';
}