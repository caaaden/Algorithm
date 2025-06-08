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

    auto findGroups = [](const string& s) {
        vector<pii> ret;
        int n = s.size();
        int cnt = 0;
        for (int i = 0; i < n-1; ++i) {
            if (s[i] == s[i+1]) {
                cnt++;
            } else {
                if (cnt) {
                    ret.push_back({i-cnt, cnt+1});
                    cnt = 0;
                }
            }
        }
        if (cnt) {
            ret.push_back({n-1-cnt, cnt+1});
        }
        return ret;
    };

    function<bool(const string&)> dfs = [&](const string& s) {
        if (s == "") {
            return true;
        }
        vector<pii> groups = findGroups(s);
        if (groups.empty()) return false;
        bool flag = false;
        for (auto& [i, l] : groups) {
            string tmp = s.substr(0, i) + s.substr(i+l);
            flag = flag || dfs(tmp);
        }
        return flag;
    };

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << dfs(s) << '\n';
    }
}

