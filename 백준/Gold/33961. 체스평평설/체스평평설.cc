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
const long long MOD = 1e9 + 7;
const long long MOD2 = 1e9 + 9;
const int MAX = 1e9;

int main(){
    fastio;

    int n; cin >> n;
    if (n <= 2) {
        cout << "NO";
        return 0;
    }
    vector<pii> threePos = {{1, 1}, {2, 3}, {1, 2},
                            {2, 1}, {1, 3}, {2, 2}};
    vector<pii> fourPos = {{1, 1}, {2, 2}, {1, 4}, {2, 3},
                           {1, 2}, {2, 1}, {1, 3}, {2, 4}};
    vector<pii> fivePos = {{1, 2}, {2, 1}, {1, 3},
                           {2, 4}, {1, 5}, {2, 3},
                           {1, 1}, {2, 2}, {1, 4}, {2, 5}};

    auto display = [](vector<pii>& pos, int idx) {
        for (auto& [a, b] : pos) {
            cout << a << ' ' << b + idx << endl;
        }
    };

    cout << "YES" << endl;
    if (n == 3) {
        display(threePos, 0);
        return 0;
    }
    if (n == 4) {
        display(fourPos, 0);
        return 0;
    }
    if (n == 5) {
        display(fivePos, 0);
        return 0;
    }
    if (n % 3 == 0) {
        for (int i = 0; i < n; i += 3) {
            display(threePos, i);
        }
    } else if (n % 3 == 1) {
        for (int i = 0; i < n-4; i += 3) {
            display(threePos, i);
        }
        display(fourPos, n-4);
    } else {
        for (int i = 0; i < n-8; i += 3) {
            display(threePos, i);
        }
        display(fourPos, n-8);
        display(fourPos, n-4);
    }
}