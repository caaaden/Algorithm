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
const long long MOD1 = 1e9 + 7;
const long long MOD2 = 1e9 + 9;
const int MAX = 1e9;

int main(){
    fastio;

    auto failure = [](const string& s) {
        vector<int> f(s.size());
        for (int j = 0, i = 1; i < s.size(); ++i) {
            while (j > 0 && s[i] != s[j]) j = f[j-1];
            if (s[i] == s[j]) f[i] = ++j;
        }
        return f;
    };
    
    string s; cin >> s;
    vector<int> f = failure(s);
    if (f.back() == 0) {
        cout << -1;
    } else {
        for (int i = 0; i < s.size()-1; ++i) {
            if (f[i] == f.back()) {
                cout << s.substr(0, f.back());
                return 0;
            }
        }
        int x = f[f.back()-1];
        if (x == 0) {
            cout << -1;
            return 0;
        }
        cout << s.substr(0, x);
    }
}