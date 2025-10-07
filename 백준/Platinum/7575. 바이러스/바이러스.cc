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

    int n, k; cin >> n >> k;
    vector<vector<int>> programs(n);
    for (auto& program : programs) {
        int m; cin >> m;
        program.resize(m);
        for (int i = 0; i < m; ++i) {
            cin >> program[i];
        }
    }

    auto mod1 = [&](ll x) {
        return ((x % MOD1) + MOD1) % MOD1;
    };

    auto mod2 = [&](ll x) {
        return ((x % MOD2) + MOD2) % MOD2;
    };

    auto doubleHash = [&](vector<int>& program, int w) {
        // program을 w 사이즈로 더블 해싱
        vector<pii> hashVal;
        if (program.size() < w) return hashVal;
        const ll BASE1 = 10007;
        const ll BASE2 = 10009;

        ll hash1 = 0, hash2 = 0;
        ll power1 = 1, power2 = 1;

        for (int i = 0; i < w-1; ++i) {
            power1 = mod1(power1 * BASE1);
            power2 = mod2(power2 * BASE2);
        }

        for (int i = 0; i < w; ++i) {
            hash1 = mod1(hash1 * BASE1 + program[i]);
            hash2 = mod2(hash2 * BASE2 + program[i]);
        }
        hashVal.push_back({hash1, hash2});

        for (int i = 0; i < program.size()-w; ++i) {
            hash1 = mod1(hash1 - mod1((ll)program[i] * power1));
            hash1 = mod1(hash1 * BASE1 + program[i+w]);

            hash2 = mod2(hash2 - mod2((ll)program[i] * power2));
            hash2 = mod2(hash2 * BASE2 + program[i+w]);

            hashVal.push_back({hash1, hash2});
        }

        return hashVal;
    };

    auto check = [&](int w) {
        vector<vector<pii>> hashValues(2);
        vector<int> tmp = programs[0];
        hashValues[0] = doubleHash(tmp, w);
        reverse(all(tmp));
        hashValues[1] = doubleHash(tmp, w);
        reverse(all(hashValues[1]));

        vector<set<pii>> hashSet(n);
        for (int i = 1; i < n; ++i) {
            vector<pii> forward = doubleHash(programs[i], w);
            for (auto& e : forward) {
                hashSet[i].insert(e);
            }
        }

        for (int i = 0; i < hashValues[0].size(); ++i) {
            // hashValues[0][i], hashValues[1][i]
            pii a = hashValues[0][i]; // 순방향 hash value
            pii b = hashValues[1][i]; // 역방향 hash value
            bool isPossible = true;
            for (int j = 1; j < n; ++j) {
                if (!hashSet[j].count(a) && !hashSet[j].count(b)) {
                    isPossible = false;
                    break;
                }
            }
            if (isPossible) return true;
        }
        return false;
    };

    auto binarySearch = [&]() {
        int lo = -1, hi = 1001;
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

    int maxLen = binarySearch();
    cout << (maxLen >= k ? "YES" : "NO");
}