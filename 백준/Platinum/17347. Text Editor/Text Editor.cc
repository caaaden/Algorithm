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

template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

constexpr int dx[4] = {1, -1, 0, 0};
constexpr int dy[4] = {0, 0, 1, -1};
constexpr int bit = 9;

int main() {
    fastio;

    crope r;
    int t, pos = 0;
    cin >> t;
    while (t--) {
        string op;
        cin >> op;
        if (op == "Move") {
            int k;
            cin >> k;
            pos = k;
        } else if (op == "Insert") {
            int n;
            cin >> n;
            string s;
            int cnt = 0;
            while (true) {
                string tmp;
                getline(cin, tmp);
                cnt += tmp.size();
                s += tmp;
                if (cnt == n) break;
            }
            crope tmp(s.c_str());
            r.insert(pos, tmp);
        } else if (op == "Delete") {
            int n;
            cin >> n;
            r.erase(pos, n);
        } else if (op == "Get") {
            int n;
            cin >> n;
            cout << r.substr(pos, n) << '\n';
        } else if (op == "Prev") {
            --pos;
        } else {
            ++pos;
        }
    }
}