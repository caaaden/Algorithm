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

    // dp[a] = a를 증가 팰린드롬 부분 문자열의 끝으로 할 때 그것의 최대 길이
    // dp[a] = 3
    // a-2, a-1, a
    // a-1이 중심
    // v[a+1], v[a-3]이 같으면서, v[a+1] > v[a]를 만족할 경우
    // dp[a+1] = dp[a] + 1
    // else dp[a+1] = 1
    // v[a+1], v[a-dp[a]]
    // a-dp[a]가 범위를 벗어날 경우? dp[a+1] = 1

    // 길이가 짝수일 경우
    // i > 0, v[i] == v[i-1]이면 dp[i] = 2
    // v[a-dp[a]] == v[a+1] && v[a] > v[a+1]

    // dp값 중 최댓값 -> ans
    int n; cin >> n;
    vector<int> v(n);
    for (auto& e : v) cin >> e;
    vector<int> dp(n, 1);
    for (int i = 1; i < n; ++i) {
        if (v[i] == v[i-1]) dp[i] = 2;
    }
    // a-dp[a] < 0
    // a < dp[a]
    for (int i = 0; i < n-1; ++i) {
        if (i < dp[i]) continue;
        if (v[i-dp[i]] == v[i+1] && v[i] > v[i+1]) {
            dp[i+1] = dp[i] + 2;
        }
    }
    // 0...n-1
    cout << *max_element(all(dp));
}