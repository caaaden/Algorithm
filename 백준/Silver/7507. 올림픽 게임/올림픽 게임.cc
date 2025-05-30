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

    auto timeToMin = [](int t) {
        return (t / 100) * 60 + (t % 100);
    };

    int t;
    cin >> t;
    int idx = 1;
    while (t--) {
        int n;
        cin >> n;
        // 날짜별로 분리
        unordered_map<int, vector<pii>> day;
        for (int i = 0; i < n; ++i) {
            int d, s, e;
            cin >> d >> s >> e;
            day[d].push_back({timeToMin(s), timeToMin(e)});
        }
        int cnt = 0;
        for (auto& [d, v] : day) {
            sort(all(v), [](const pii& a, const pii& b) {
                return a.second < b.second;
            });
            // greedy하게 선택,
            int now = -1;
            for (auto& [s, e] : v) {
                if (now > s) continue;
                now = e;
                cnt++;
            }
        }
        cout << "Scenario #" << idx++ << ':' << '\n';
        cout << cnt << '\n' << '\n';
    }
}