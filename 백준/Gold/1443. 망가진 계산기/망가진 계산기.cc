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

    int d, p;
    cin >> d >> p;
    // 이게 시간 안에 돌아간다고?
    // 겹치거나 자릿수를 넘어가면 가지치기
    // d = 4 : 9999, x < 10^4
    int MAX = 1;
    for (int i = 0; i < d; ++i) MAX *= 10;
    int ans = -1;
    int num = 1;
    function<void(int, int)> dfs = [&](int dep, int last) {
        if (dep == p) {
            ans = max(ans, num);
            return;
        }
        for (int i = last; i <= 9; ++i) {
            if (num*i >= MAX) continue;
            num *= i;
            dfs(dep+1, i);
            num /= i;
        }

    };
    dfs(0, 2);
    cout << ans;
}