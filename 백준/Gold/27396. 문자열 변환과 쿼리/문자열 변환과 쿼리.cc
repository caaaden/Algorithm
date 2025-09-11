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

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

constexpr int dx[4] = {1, -1, 0, 0};
constexpr int dy[4] = {0, 0, 1, -1};
constexpr int bit = 9;
const long long MOD = 1e9 + 7;
const int MAX = 1e9;

int main(){
    fastio;

    string s;
    int n;
    cin >> s >> n;
    string t;
    for (int i = 0; i < 26; ++i) t += i + 'a';
    for (int i = 0; i < 26; ++i) t += i + 'A';
    while (n--) {
        int op; cin >> op;
        if (op == 1) {
            char x, y; cin >> x >> y;
            for (auto& c : t) if (c == x) c = y;
        } else {
            for (auto& c : s) {
                if (isupper(c)) cout << t[c - 'A' + 26];
                else cout << t[c - 'a'];
            }
            cout << '\n';
        }
    }
}