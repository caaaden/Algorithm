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
    queue<pii> q;
    int mx = 0;
    int num = 0;
    vector<int> A, B, C;
    for (int i = 0; i < n; ++i) {
        int op; cin >> op;
        if (op == 1) {
            int a, b; cin >> a >> b;
            q.push({a, b});
        } else {
            int b; cin >> b;
            if (q.front().Y == b) {
                A.push_back(q.front().X);
            } else {
                B.push_back(q.front().X);
            }
            q.pop();
        }
    }
    while (q.size()) {
        C.push_back(q.front().X);
        q.pop();
    }
    sort(all(A));
    sort(all(B));
    sort(all(C));
    if (A.empty()) cout << "None" << '\n';
    else {
        for (auto& e : A) cout << e << ' ';
        cout << '\n';
    }
    if (B.empty()) cout << "None" << '\n';
    else {
        for (auto& e : B) cout << e << ' ';
        cout << '\n';
    }
    if (C.empty()) cout << "None" << '\n';
    else {
        for (auto& e : C) cout << e << ' ';
        cout << '\n';
    }
}