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
const int MOD = 1e9 + 7;
// const ll MOD = 1e9 + 7;

int main(){
    fastio;

    auto isBinaryPalindrome = [](int x) {
        string b;
        while (x) {
            b += (x & 1) + '0';
            x >>= 1;
        }
        for (int i = 0; i < b.size()/2; ++i) {
            if (b[i] == b[b.size()-1-i]) continue;
            return false;
        }
        return true;
    };

    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        if (isBinaryPalindrome(x)) {
            cout << 0 << '\n';
            continue;
        }
        int cntUp = 0, cntDn = 0;
        int tmp = x;
        do {
            tmp++;
            cntUp++;
        } while (!isBinaryPalindrome(tmp));
        tmp = x;
        do {
            tmp--;
            cntDn++;
        } while (!isBinaryPalindrome(tmp));
        cout << min(cntUp, cntDn) << '\n';
    }
}