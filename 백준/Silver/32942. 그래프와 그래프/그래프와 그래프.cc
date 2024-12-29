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

    int a, b, c;
    cin >> a >> b >> c;
    vector<int> graph[11];
    for (int i = 1; i <= 10; ++i) {
        for (int j = 1; j <= 10; ++j) {
            if (a * i + b * j == c) graph[i].push_back(j);
        }
    }
    for (int i = 1; i <= 10; ++i) {
        if (graph[i].empty()) cout << 0 << '\n';
        else {
            for (auto& e : graph[i]) cout << e << ' ';
            cout << '\n';
        }
    }
}