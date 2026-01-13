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
constexpr int dx2[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
constexpr int dy2[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
constexpr int bit = 9;
const long long MOD = 1e9 + 7;
const long long MOD2 = 1e9 + 9;
const int MAX = 1e9;

int main() {
    fastio;

    auto getPeriod = [](int n) {
        vector<int> v(n);
        for (int j = 0; j < n; ++j) v[j] = j;
        int cnt = 0;
        vector<int> vec = v;
        while (true) {
            cnt++;
            vector<int> newVec;
            newVec.reserve(n);
            for (int i = 0; i < n; i += 2) {
                newVec.push_back(vec[i]);
            }
            for (int i = n-1-(n&1); i >= 0; i -= 2) {
                newVec.push_back(vec[i]);
            }
            if (v == newVec) break;
            swap(vec, newVec);
        }
        return cnt;
    };

    int x; cin >> x;
    string s; cin >> s;
    int p = getPeriod(s.size());
    x %= p;
    for (int i = 0; i < x; ++i) {
        string newStr;
        for (int j = 0; j < s.size(); j += 2) {
            newStr += s[j];
        }
        for (int j = s.size()-1-(s.size()&1); j >= 0; j -= 2) {
            newStr += s[j];
        }
        swap(s, newStr);
    }
    cout << s;
}