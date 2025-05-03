#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

#define fastio ios::sync_with_stdio(0), cin.tie(0)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define X first
#define Y second
#define rep(i, a, b) for (int i = a; i < b; ++i)

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using psi = pair<string, int>;
using piii = pair<int, pii>;
using piiii = pair<pii, pii>;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

constexpr int dx[4] = {1, -1, 0, 0};
constexpr int dy[4] = {0, 0, 1, -1};
constexpr int bit = 9;
const long long MOD = 1e9 + 7;

int main(){
    fastio;

    vector<int> goldMinsu = {4, 7};
    for (int i = 1; i < 6; ++i) {
        int sz = goldMinsu.size();
        vector<int> tmp;
        for (int j = sz - (1 << i); j < sz; ++j) {
            tmp.push_back(goldMinsu[j] * 10 + 4);
            tmp.push_back(goldMinsu[j] * 10 + 7);
        }
        goldMinsu.insert(goldMinsu.end(), all(tmp));
    }
    vector<vector<int>> dp(1000001);
    for (int i = 1; i <= 1000000; ++i) {
        // 후보 벡터
        vector<int> cands;
        bool flag = false;
        int gold = 0; // 금민수
        for (auto& e : goldMinsu) {
            // e = 4, 7, 44, 47, ...
            // i >= e
            if (i < e) break;
            if (i == e) {
                flag = true;
                break;
            }
            // i > e
            if (dp[i-e].empty()) continue;
            if (cands.empty()) {
                cands = dp[i-e];
                gold = e;
            } else {
                // cands.size(), dp[i-e].size()
                if (cands.size() > dp[i-e].size()) {
                    // dp[i-e]가 우선순위
                    cands = dp[i-e];
                    gold = e;
                } else if (cands.size() == dp[i-e].size()){
                    // 개수가 같을 경우 사전순
                    // cands, dp[i-e]를 비교, 더 작은 걸 구하기
                    if (cands > dp[i-e]) {
                        cands = dp[i-e];
                        gold = e;
                    }
                }
            }
        }
        if (flag) {
            // i == e일 경우
            dp[i] = {i};
            continue;
        }
        if (!gold) {
            // 금민수의 합으로 나타낼 수 없는 경우
            continue;
        }
        auto it = lower_bound(all(cands), gold);
        cands.insert(it, gold);
        dp[i] = cands;
    }
    int n;
    cin >> n;
    if (dp[n].empty()) {
        cout << -1;
        return 0;
    }
    for (auto& e : dp[n]) {
        cout << e << ' ';
    }
}