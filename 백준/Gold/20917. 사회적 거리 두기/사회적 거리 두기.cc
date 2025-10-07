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
const long long MOD1 = 1e9 + 7;
const long long MOD2 = 1e9 + 9;
const int MAX = 1e9;

int main(){
    fastio;

    int t; cin >> t;
    while (t--) {
        int n, s; cin >> n >> s;
        // d에 대해 이분 탐색, 설치할 수 있는 지점 s개 이상,
        // d 최댓값?
        // TT...TF...FF
        vector<int> v(n);
        for (auto& e : v) cin >> e;
        sort(all(v));
        // 0, MAX+1

        auto check = [&](int x) {
            // 거리 = x
            // 몇 개나 설치?
            int cnt = 1;
            int cur = v[0];
            for (auto& e : v) {
                // 2, 3, 5, 9, 11, 15, 17, ...
                // d = 4
                // 2, 3x, 5x, 9, 11x
                // cur + x <= e
                if (cur+x > e) continue;
                cur = e;
                cnt++;
            }
            return cnt >= s;
        };

        int lo = 0, hi = MAX+1;
        while (lo+1 < hi) {
            int mid = (lo + hi) / 2;
            if (check(mid)) {
                lo = mid;
            } else {
                hi = mid;
            }
        }
        cout << lo << endl;
    }
}