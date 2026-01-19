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

    // 우선 두 개의 숫자를 선택 -> n^2
    // 두 숫자를 나머지 수열에서 각각 이분 탐색
    // 두 숫자 사이에 다른 숫자가 있다면?(inclusive) 두 숫자의 차 = 중간 결과값
    // 두 숫자 사이에 다른 숫자가 없다면? 두 숫자 중 작은 숫자보다 작은 값 중 최댓값과 큰 숫자보다 큰 값 중 최솟값을 구한 뒤 중간 결과값 구하기
    // n^2 logn
    int a, b, c; cin >> a >> b >> c;
    vector<int> A(a), B(b), C(c);
    for (auto& e : A) cin >> e;
    for (auto& e : B) cin >> e;
    for (auto& e : C) cin >> e;
    sort(all(A));
    sort(all(B));
    sort(all(C));
    int ans = INT_MAX;
    for (auto l : A) {
        for (auto r : B) {
            bool swapped = false;
            if (l > r) {
                swap(l, r);
                swapped = true;
            }
            int lIdx = lower_bound(all(C), l) - C.begin();
            lIdx--;
            int rIdx = upper_bound(all(C), r) - C.begin();
            if (rIdx - lIdx < 2) {
                int mn = INT_MAX;
                if (lIdx != -1) mn = min(mn, r - C[lIdx]);
                if (rIdx != c) mn = min(mn, C[rIdx] - l);
                ans = min(ans, mn);
            } else {
                ans = min(ans, r - l);
            }
            if (swapped) swap(l, r);
        }
    }
    cout << ans;
}