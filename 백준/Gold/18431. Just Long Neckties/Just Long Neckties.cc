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

    int n;
    cin >> n;
    vector<pii> a(n+1);
    vector<int> b(n);
    for (int i = 0; i <= n; ++i) {
        cin >> a[i].X;
        a[i].Y = i;
    }
    for (auto& e : b) cin >> e;
    sort(all(a));
    // 안정 정렬일 이유? x?
    sort(all(b));
    vector<int> pMax(n), sMax(n);
    for (int i = 0; i < n; ++i) {
        pMax[i] = max(i ? pMax[i-1] : 0, max(a[i].X-b[i], 0)); // c
    }
    for (int i = n-1; i >= 0; --i) {
        sMax[i] = max(i != n-1 ? sMax[i+1] : 0, max(a[i+1].X-b[i], 0));
    }
    vector<int> c(n+1);
    // 정렬하기 전 인덱스를 보관
    for (int i = 0; i <= n; ++i) {
        // max(i ? pMax[i-1] : 0, i != n ? sMax[i] : 0)
        // a[i].Y에 저장
        c[a[i].Y] = max(i ? pMax[i-1] : 0, i != n ? sMax[i] : 0);
    }
    for (int i = 0; i <= n; ++i) cout << c[i] << ' ';
}