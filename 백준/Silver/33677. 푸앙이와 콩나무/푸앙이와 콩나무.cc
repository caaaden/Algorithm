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
    vector<pii> dist(n+1, {-1, -1});
    dist[0] = {0, 0};
    queue<piii> Q;
    Q.push({0, {0, 0}});
    while (Q.size()) {
        piii now = Q.front(); Q.pop();
        if (now.X == n) {
            cout << dist[now.X].X << ' ' << dist[now.X].Y;
            return 0;
        }
        // {길이, {일수, 물의 양}}
        for (auto& [next, cost] : {pli{now.X+1, 1}, pli{now.X*3, 3}, pli{(ll)now.X*now.X, 5}}) {
            if (next > n) continue;
            if (dist[next].X == -1) {
                // 방문한 적이 없다면,
                dist[next].X = dist[now.X].X + 1;
                dist[next].Y = dist[now.X].Y + cost;
                Q.push({next, dist[next]});
                continue;
            }
            if (dist[next].X == now.Y.X + 1 && dist[next].Y > now.Y.Y + cost) {
                dist[next].Y = now.Y.Y + cost;
                Q.push({next, dist[next]});
            }
        }
    }
}