#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

#define fastio ios::sync_with_stdio(0), cin.tie(0);
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
    
    int n, s;
    cin >> n >> s;
    vector<int> x(n+1), h(n+1);
    for (int i = 1; i <= n; ++i) cin >> x[i];
    for (int i = 1; i <= n; ++i) cin >> h[i];
    auto cmp = [](const int& a, const int& b) {
        return a < b;
    };
    multimap<int, pii, decltype(cmp)> mp(cmp);
    queue<piii> Q;
    for (int i = 1; i <= n; ++i) {
        if (i == s) {
            Q.push({x[i], {h[i], i}});
        } else {
            mp.insert({x[i], {h[i], i}});
        }
    }
    vector<int> ans;
    while (Q.size()) {
        int start = Q.front().X - Q.front().Y.X;
        int end = Q.front().X + Q.front().Y.X;
        ans.push_back(Q.front().Y.Y);
        Q.pop();
        auto it = mp.lower_bound(start);
        while (it != mp.end() && it->first <= end) {
            Q.push({it->first, {it->second.first, it->second.second}});
            it = mp.erase(it);
        }
    }
    sort(all(ans));
    for (auto& e : ans) cout << e << ' ';
}