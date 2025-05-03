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

    ll a = 0;
    vector<ll> eightNums;
    for (int i = 0; i < 18; ++i) {
        a = a * 10 + 8;
        eightNums.push_back(a);
    }
    reverse(all(eightNums));
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        int cnt = 0;
        // 104
        // 88 + 8 + 8
        for (auto& eightNum : eightNums) {
            while (true) {
                if (eightNum > n) break;
                ++cnt;
                n -= eightNum;
                if (!n) break;
            }
        }
        if (!n && cnt <= 8) {
            cout << "Yes" << '\n';
        } else {
            cout << "No" << '\n';
        }
    }
}