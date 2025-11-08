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
constexpr int dx2[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
constexpr int dy2[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
constexpr int bit = 9;
const long long MOD = 1e9 + 7;
const long long MOD2 = 1e9 + 9;
const int MAX = 1e9;

int main() {
    fastio;

    auto getDigit = [](ll x) {
        int cnt = 0;
        while (x) {
            cnt++;
            x /= 10;
        }
        return cnt;
    };

    ll n; cin >> n;
    if (n >= 9876543210LL) {
        cout << 9876543210LL;
        return 0;
    }
    int digit = getDigit(n);
    // 10개 중 digit개 뽑기
    ll minDiff = 1e15;
    ll ans;
    for (int i = 0; i < (1 << 10); ++i) {
        int cnt = __builtin_popcount(i); // 1의 개수
        if (cnt != digit) continue;
        // 선택된 숫자들에 대해 permutation
        // 맨 앞이 0인 경우 제외
        string num;
        for (int j = 0; j < 10; ++j) {
            if (i & (1 << j)) {
                // j 자체가 선택된 숫자
                num += j + '0';
            }
        }
        do {
            // num[0]이 0인 경우는 continue
            if (num[0] == '0') continue;
            ll x = stoll(num);
            // n과 x를 비교,
            if (minDiff > abs(n - x)) {
                // 최소 차이를 갱신하는 경우
                minDiff = abs(n - x);
                ans = x;
            }
        } while (next_permutation(all(num)));
    }
    string low = "987654321";
    string high = "1023456789";
    if (digit > 1) {
        ll l = stoll(low.substr(0, digit-1));
        if (n - l <= minDiff) {
            minDiff = n - l;
            ans = l;
        }
    }
    if (digit < 10) {
        ll h = stoll(high.substr(0, digit+1));
        if (h - n < minDiff) {
            minDiff = h - n;
            ans = h;
        }
    }
    cout << ans;
}