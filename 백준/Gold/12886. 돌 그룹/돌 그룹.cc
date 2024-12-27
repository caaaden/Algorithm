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
    int sum = a + b + c;
    vector<vector<int>> vis(1001, vector<int>(1001));
    vector<int> tmp = {a, b, c};
    sort(all(tmp));
    vis[a][b] = 1;
    queue<vector<int>> Q;
    Q.push(tmp);
    while (Q.size()) {
        vector<int> now = Q.front();
        Q.pop();
        if (now[0] == now[1] && now[1] == now[2]) {
            cout << 1;
            return 0;
        }
        if (now[0] < now[1]) {
            int x = now[0] * 2;
            int y = now[1] - now[0];
            vector<int> tmp2 = {x, y, now[2]};
            sort(all(tmp2));
            if (!vis[tmp2[0]][tmp2[1]]) {
                vis[tmp2[0]][tmp2[1]] = 1;
                Q.push(tmp2);
            }
        }
        if (now[0] < now[2]) {
            int x = now[0] * 2;
            int y = now[2] - now[0];
            vector<int> tmp2 = {x, y, now[1]};
            sort(all(tmp2));
            if (!vis[tmp2[0]][tmp2[1]]) {
                vis[tmp2[0]][tmp2[1]] = 1;
                Q.push(tmp2);
            }
        }
        if (now[1] < now[2]) {
            int x = now[1] * 2;
            int y = now[2] - now[1];
            vector<int> tmp2 = {x, y, now[0]};
            sort(all(tmp2));
            if (!vis[tmp2[0]][tmp2[1]]) {
                vis[tmp2[0]][tmp2[1]] = 1;
                Q.push(tmp2);
            }
        }
    }
    cout << 0;
}