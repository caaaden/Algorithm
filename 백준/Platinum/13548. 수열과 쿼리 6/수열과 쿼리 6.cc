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

    int n;
    cin >> n;
    int sq = sqrt(n);
    vector<int> v(n+1);
    for (int i = 1; i <= n; ++i) cin >> v[i];
    vector<int> cnt(100001); // 특정 숫자의 빈도를 저장
    vector<int> cnt2(100001); // 특정 빈도에 숫자가 몇 개 있는지 저장
    int cntMax = 0; // 최대 빈도를 저장
    int m;
    cin >> m;
    vector<piii> query(m);
    vector<ll> ans(m);
    for (int i = 0; i < m; ++i) {
        int s, e;
        cin >> s >> e;
        query[i] = {i, {s, e}};
    }
    sort(all(query), [&sq](const piii& a, const piii& b) {
        if (a.Y.X/sq == b.Y.X/sq) return a.Y.Y < b.Y.Y;
        return a.Y.X/sq < b.Y.X/sq;
    });
    int s = query[0].Y.X, e = query[0].Y.Y;
    cnt2[0] = n; // 빈도 0이 n개
    for (int i = s; i <= e; ++i) {
        cnt2[cnt[v[i]]]--;
        cnt[v[i]]++;
        cnt2[cnt[v[i]]]++; // 해당 빈도 개수 증가
        cntMax = max(cntMax, cnt[v[i]]); // 빈도의 최댓값
    }
    // cnt[a] : a의 빈도
    // cnt2[a] : 빈도 a를 가지는 숫자의 개수
    ans[query[0].X] = cntMax;
    for (int i = 1; i < m; ++i) {
        int qs = query[i].Y.X;
        int qe = query[i].Y.Y;
        while (e < qe) {
            ++e;
            // v[e] 추가,
            cnt2[cnt[v[e]]]--;
            cnt[v[e]]++;
            cnt2[cnt[v[e]]]++;
            cntMax = max(cntMax, cnt[v[e]]);
        }
        while (s < qs) {
            // v[s] 제거
            cnt2[cnt[v[s]]]--;
            if (!cnt2[cnt[v[s]]] && cnt[v[s]] == cntMax) cntMax--;
            cnt[v[s]]--;
            cnt2[cnt[v[s]]]++;
            ++s;
        }
        while (e > qe) {
            // v[e] 제거
            cnt2[cnt[v[e]]]--;
            if (!cnt2[cnt[v[e]]] && cnt[v[e]] == cntMax) cntMax--;
            cnt[v[e]]--;
            cnt2[cnt[v[e]]]++;
            --e;
        }
        while (s > qs) {
            --s;
            // v[s] 추가
            cnt2[cnt[v[s]]]--;
            cnt[v[s]]++;
            cnt2[cnt[v[s]]]++;
            cntMax = max(cntMax, cnt[v[s]]);
        }
        ans[query[i].X] = cntMax;
    }
    for (auto& e : ans) cout << e << '\n';

}