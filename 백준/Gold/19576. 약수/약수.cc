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
#define pb push_back
#define endl '\n'

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

//template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T, typename Compare = less<T>>
using ordered_set = tree<T, null_type, Compare, rb_tree_tag, tree_order_statistics_node_update>;

constexpr int dx[4] = {1, -1, 0, 0};
constexpr int dy[4] = {0, 0, 1, -1};
constexpr int bit = 9;
const long long MOD = 1e9 + 7;
const long long MOD2 = 1e9 + 9;
const int MAX = 1e9;

int main(){
    fastio;

    // 정렬 -> 작은 것부터 순서대로 순회, push dp,
    // dp[i] = v[i]까지 가는 데 최대 횟수(약수의 최대 개수?)
    // n^2
    // dp[i] 중 최댓값
    // 전체 개수 - 최댓값 = 약수로 변경해야 하는 숫자의 최소 개수
    int n; cin >> n;
    vector<int> v(n);
    for (auto& e : v) cin >> e;
    sort(all(v));
    // 3 4 6 10 24
    vector<int> dp(n, 1);
    // dp[i]의 초깃값 = 1
    for (int i = 0; i < n; ++i) {
        // dp[i]에서 i < j인 dp[j]에게 뿌리기
        for (int j = i+1; j < n; ++j) {
            // v[i], v[j]
            // v[j] % v[i] == 0
            if (v[j] % v[i]) continue;
            dp[j] = max(dp[j], dp[i]+1);
        }
    }
    int mx = 1;
    for (int i = 0; i < n; ++i) {
        // dp[i]의 최댓값
        mx = max(mx, dp[i]);
    }
    // n - mx
    cout << n - mx;
}