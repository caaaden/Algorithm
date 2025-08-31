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

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
using psi = pair<string, int>;
using piii = pair<pii, int>;
using piiii = pair<pii, pii>;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

constexpr int dx[4] = {1, -1, 0, 0};
constexpr int dy[4] = {0, 0, 1, -1};
constexpr int bit = 9;
const long long MOD = 1e9 + 7;
const int MAX = 1e9;

int main() {
    fastio;

    int n; cin >> n;
    vector<pii> v(n);
    vector<int> copied;
    copied.reserve(n*2);
    for (auto& [a, b] : v) {
        cin >> a >> b;
        copied.pb(a);
        copied.pb(b);
    }
    sort(all(copied));
    copied.erase(unique(all(copied)), copied.end());

    auto getIdx = [&copied](int x) {
        return lower_bound(all(copied), x) - copied.begin();
    };

    vector<pii> compressed(n);
    for (int i = 0; i < n; ++i) {
        compressed[i] = {getIdx(v[i].X), getIdx(v[i].Y)};
    }
    vector<int> diffArr(copied.size());
    for (auto& [a, b] : compressed) {
        diffArr[a]++;
        diffArr[b]--;
    }
    int mx = diffArr[0];
    for (int i = 1; i < diffArr.size(); ++i) {
        diffArr[i] += diffArr[i-1];
        mx = max(mx, diffArr[i]);
    }
    int s = -1, e = -1;
    bool found = false;
    for (int i = 0; i < diffArr.size(); ++i) {
        if (diffArr[i] != mx) {
            if (found) break;
            continue;
        }
        if (!found) found = true;
        if (s == -1) s = i;
        e = i;
    }
    cout << mx << '\n';
    cout << copied[s] << ' ' << copied[e+1];
}

