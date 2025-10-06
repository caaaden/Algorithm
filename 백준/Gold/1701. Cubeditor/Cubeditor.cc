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

    string s; cin >> s;
    int n = s.size();

    auto mod1 = [&](ll x) {
        return ((x % MOD1) + MOD1) % MOD1;
    };

    auto mod2 = [&](ll x) {
        return ((x % MOD2) + MOD2) % MOD2;
    };

    auto check = [&](int w) {
        const ll BASE1 = 31;
        const ll BASE2 = 37;

        ll hash1 = 0, hash2 = 0;
        ll power1 = 1, power2 = 1;

        for (int i = 0; i < w-1; ++i) {
            power1 = mod1(power1 * BASE1);
            power2 = mod2(power2 * BASE2);
        }

        map<pii, int> cnt;
        
        for (int i = 0; i < w; ++i) {
            hash1 = mod1(hash1 * BASE1 + s[i]);
            hash2 = mod2(hash2 * BASE2 + s[i]);
        }
        cnt[{hash1, hash2}]++;
        
        for (int i = 0; i < n-w; ++i) {
            hash1 = mod1(hash1 - mod1((ll)s[i] * power1));
            hash1 = mod1(hash1 * BASE1 + s[i+w]);

            hash2 = mod2(hash2 - mod2((ll)s[i] * power2));
            hash2 = mod2(hash2 * BASE2 + s[i+w]);

            cnt[{hash1, hash2}]++;
        }

        for (auto& [hash_pair, count] : cnt) {
            if (count >= 2) {
                return true;
            }
        }
        return false;
    };

    auto binarySearch = [&]() {
        int lo = 0, hi = s.size()+1;
        while (lo + 1 < hi) {
            int mid = (lo + hi) / 2;
            if (check(mid)) {
                lo = mid;
            } else {
                hi = mid;
            }
        }
        return lo;
    };

    int ans = binarySearch();
    cout << ans;
}