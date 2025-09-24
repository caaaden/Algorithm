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

    int n, l; cin >> n >> l;

    auto check = [&](const string& a, const string& b) {
        int diffCnt = 0;
        for (int i = 0; i < l; ++i) {
            if (a[i] == b[i]) continue;
            diffCnt++;
        }
        return diffCnt <= 1;
    };

    vector<string> v(n);
    for (auto& e : v) cin >> e;
    for (auto& str : v) {
        for (int i = 0; i < l; ++i) {
            for (int j = 0; j < 26; ++j) {
                string candidate = str.substr(0, i);
                candidate += j + 'A';
                candidate += str.substr(i+1);
                bool possible = true;
                for (auto& str2 : v) {
                    if (check(candidate, str2)) continue;
                    possible = false;
                    break;
                }
                if (possible) {
                    cout << candidate;
                    return 0;
                }
            }
        }
    }
    cout << "CALL FRIEND";
}