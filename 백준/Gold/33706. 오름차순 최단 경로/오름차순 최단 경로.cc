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

    int n, m;
    cin >> n >> m;
    vector<int> graph[n+1];
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    // 1부터 순회
    vector<int> vis(n+1);
    vis[1] = 1;
    queue<int> Q;
    Q.push(1);
    while (Q.size()) {
        int now = Q.front();
        Q.pop();
        for (auto& next : graph[now]) {
            if (vis[next]) continue;
            vis[next] = 1;
            Q.push(next);
        }
    }
    for (int i = 1; i <= n; ++i) {
        // vis[i]
        if (vis[i]) continue;
        cout << "NO";
        return 0;
    }
    cout << "YES";
}