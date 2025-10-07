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

    auto isUnique = [&](const string& t, const string& p) {
        vector<int> f = failure(p);
        vector<int> matches;
        for (int j = 0, i = 0; i < t.size(); ++i) {
            while (j > 0 && t[i] != p[j]) j = f[j-1];
            if (t[i] == p[j]) {
                if (j == p.size()-1) {
                    matches.push_back(i-j+1);
                    j = f[j];
                } else ++j;
            }
        }
        return matches.size() == 1;
    };

    int t; cin >> t;
    while (t--) {
        string order, plain, cipher;
        cin >> order >> plain >> cipher;
        vector<int> reverseOrder(123);
        for (int i = 0; i < order.size(); ++i) {
            reverseOrder[order[i]] = i;
        }
        vector<int> ans;
        for (int i = 0; i < order.size(); ++i) {
            if (i) {
                for (auto& c : cipher) {
                    int pos = reverseOrder[c] + 1;
                    if (pos == order.size()) pos = 0;
                    c = order[pos];
                }
            }
            if (isUnique(cipher, plain)) {
                ans.push_back(i);
            }
        }
        for (auto& e : ans) {
            e = (order.size()-e) % order.size();
        }
        sort(all(ans));
        if (ans.empty()) {
            cout << "no solution" << endl;
        } else if (ans.size() == 1) {
            cout << "unique: " << ans[0] << endl;
        } else {
            cout << "ambiguous: ";
            for (auto& e : ans) cout << e << ' ';
            cout << endl;
        }
    }
}