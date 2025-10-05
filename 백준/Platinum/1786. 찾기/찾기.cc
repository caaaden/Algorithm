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
const long long MOD = 1e9 + 7;
const long long MOD2 = 1e9 + 9;
const int MAX = 1e9;

int main(){
    fastio;

    auto computeLPS = [&](const string& p) {
        vector<int> lps(p.size());
        int len = 0;
        int i = 1;
        while (i < p.size()) {
            if (p[i] == p[len]) {
                len++;
                lps[i] = len;
                ++i;
            } else {
                if (len) {
                    len = lps[len-1];
                } else {
                    lps[i] = 0;
                    ++i;
                }
            }
        }
        return lps;
    };

    auto KMPSearch = [&](const string& t, const string& p) {
        vector<int> lps = computeLPS(p);
        int i = 0, j = 0;
        vector<int> matches;
        while (i < t.size()) {
            if (t[i] == p[j]) {
                ++i;
                ++j;
            }
            if (j == p.size()) {
                matches.push_back(i-j);
                j = lps[j-1];
            } else if (i < t.size() && t[i] != p[j]) {
                if (j) j = lps[j-1];
                else ++i;
            }
        }
        return matches;
    };
    string t, p;
    getline(cin, t);
    getline(cin, p);
    vector<int> ans = KMPSearch(t, p);
    cout << ans.size() << endl;
    for (auto& e : ans) cout << e+1 << ' ';
}