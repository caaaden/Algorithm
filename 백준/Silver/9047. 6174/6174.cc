#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

#define fastio ios::sync_with_stdio(0), cin.tie(0);
#define all(v) v.begin(), v.end()
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
using piii = pair<int, pii>;
using piiii = pair<pii, pii>;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

constexpr int dx[4] = {1, -1, 0, 0};
constexpr int dy[4] = {0, 0, 1, -1};
constexpr int bit = 9;
constexpr int MOD = 1e9;

int main()
{
    fastio;
    
    auto calc = [](string x) {
        string tmp;
        for (int i = 0; i < 4 - x.size(); ++i) {
            tmp += '0';
        }
        tmp += x;
        string big = tmp;
        string small = tmp;
        sort(big.rbegin(), big.rend());
        sort(all(small));
        return to_string(stoi(big) - stoi(small));
    };
    int t;
    cin >> t;
    while (t--) {
        string n;
        cin >> n;
        int cnt;
        for (cnt = 0; n != "6174"; ++cnt) n = calc(n);
        cout << cnt << '\n';
    }
}