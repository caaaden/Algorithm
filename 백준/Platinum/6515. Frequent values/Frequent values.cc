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

    while (true) {
        int n;
        cin >> n;
        if (!n) break;
        int q;
        cin >> q;
        vector<int> v(n+1);
        for (int i = 1; i <= n; ++i) {
            cin >> v[i];
            v[i] += 100000;
        }
        vector<piii> query(q);
        vector<int> ans(q);
        for (int i = 0; i < q; ++i) {
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
        vector<int> cnt(200001);
        vector<int> cnt2(100001);
        int maxOccur = 0;
        auto add = [&v, &cnt, &cnt2, &maxOccur](int idx) {
            int val = v[idx];
            if (cnt[val]) cnt2[cnt[val]]--;
            cnt[val]++;
            cnt2[cnt[val]]++;
            maxOccur = max(maxOccur, cnt[val]);
        };
        auto remove = [&v, &cnt, &cnt2, &maxOccur](int idx) {
            int val = v[idx];
            cnt2[cnt[val]]--;
            if (cnt[val] == maxOccur && !cnt2[cnt[val]]) maxOccur--;
            cnt[val]--;
            cnt2[cnt[val]]++;
        };
        auto getAnswer = [&maxOccur]() {
            return maxOccur;
        };
        int s = query[0].Y.X, e = s - 1;
        for (int i = 0; i < q; ++i) {
            const int qs = query[i].Y.X;
            const int qe = query[i].Y.Y;
            while (e < qe) add(++e);
            while (s > qs) add(--s);
            while (e > qe) remove(e--);
            while (s < qs) remove(s++);
            ans[query[i].X] = getAnswer();
        }
        for (const auto& e : ans) cout << e << '\n';
    }
}