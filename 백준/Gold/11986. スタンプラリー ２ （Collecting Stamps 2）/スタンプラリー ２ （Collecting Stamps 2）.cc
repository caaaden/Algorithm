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

int main() {
    fastio;

    int n; cin >> n;
    string s; cin >> s;
    // JOIOI
    vector<int> idx[3]; // idx[0~2] : J O I의 인덱스 관리
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'J') idx[0].push_back(i);
        else if (s[i] == 'O') idx[1].push_back(i);
        else idx[2].push_back(i);
    }
    // 모든 위치에 O를 놓는 경우에 대해 binary search로
    // 왼쪽에 있는 J의 개수, 오른쪽에 있는 I의 개수를 찾기 및 최댓값 갱신
    // 그 최댓값에 나머지 O를 선택하는 경우의 수도 마지막에 더하기
    // J와 I를 선택하는 경우
    ll mx = 0;
    for (int i = 0; i <= n; ++i) {
        // i에 O를 놓을 경우 기존에 있던 원소는 오른쪽으로 밀린다고 가정
        // i보다 작은 J, i보다 크거나 같은 I
        ll a = lower_bound(all(idx[0]), i) - idx[0].begin() - 1;
        int b = lower_bound(all(idx[2]), i) - idx[2].begin();
        // 0~a : a+1
        // b~idx[2].size()-1 : idx[2].size()-b
        // (a+1) * (idx[2].size()-b)의 최댓값 구하기
        // edge case 조심
        mx = max(mx, (ll)((a+1) * (idx[2].size()-b)));
    }
    ll cnt = 0;
    ll JSum = 0, ISum = 0;
    // 모든 O에 대해,
    // idx[1]
    for (auto& i : idx[1]) {
        // i보다 왼쪽에 있는 J의 개수, 오른쪽에 있는 I의 개수
        // lb-1, up
        ll a = lower_bound(all(idx[0]), i) - idx[0].begin() - 1;
        ll b = upper_bound(all(idx[2]), i) - idx[2].begin();
        // 0~a : a+1
        // b~idx[2].size()-1 : idx[2].size()-b
        JSum += a+1, ISum += idx[2].size()-b;
        cnt += (a+1) * (idx[2].size()-b);
    }
    ll ans = cnt + max(mx, max(JSum, ISum));
    cout << ans;
}