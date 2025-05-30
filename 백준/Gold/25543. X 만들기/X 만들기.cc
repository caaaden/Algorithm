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

    int n;
    cin >> n;
    vector<pii> points(n);
    for (auto& [a, b] : points) cin >> a >> b;
    sort(all(points));
    vector<int> first(n, 1), second(n, 1), third(n, 1), fourth(n, 1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (points[j].X < points[i].X && points[j].Y < points[i].Y) {
                third[i] = max(third[i], third[j]+1);
            }
            if (points[j].X < points[i].X && points[j].Y > points[i].Y) {
                second[i] = max(second[i], second[j]+1);
            }
        }
    }
    for (int i = n-1; i >= 0; --i) {
        for (int j = n-1; j > i; --j) {
            if (points[i].X < points[j].X && points[i].Y < points[j].Y) {
                first[i] = max(first[i], first[j]+1);
            }
            if (points[i].X < points[j].X && points[i].Y > points[j].Y) {
                fourth[i] = max(fourth[i], fourth[j]+1);
            }
        }
    }
    int sum = -1;
    for (int i = 0; i < n; ++i) {
        if (first[i] > 1 && second[i] > 1 && third[i] > 1 && fourth[i] > 1) {
            sum = max(sum, first[i] + second[i] + third[i] + fourth[i]);
        }
    }
    if (sum == -1) {
        cout << -1;
        return 0;
    }
    sum -= 3;
    cout << n - sum;
}