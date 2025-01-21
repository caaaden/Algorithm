#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

#define fastio ios::sync_with_stdio(0), cin.tie(0);
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
using pid = pair<int, double>;
using psi = pair<string, int>;
using piii = pair<int, pii>;
using piiii = pair<pii, pii>;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

constexpr int dx[4] = {1, -1, 0, 0};
constexpr int dy[4] = {0, 0, 1, -1};
constexpr int bit = 9;
constexpr int MOD = 1e9;

int main()
{
    fastio;
    
    // leaf node가 아닌 node들에 물이 고여 있음 -> 물이 움직일 수 있는 상태 -> 끝 X
    // 끝 -> 모든 물은 leaf node에, 동일 확률? 부모가 가진 물의 양을 a, 자식의 개수를 b라고 할 때, a/b만큼 자식이 나눠 가지기.
    // 실수 연산.
    int n, w;
    cin >> n >> w;
    vector<int> graph[n+1];
    for (int i = 0; i < n-1; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    // 1부터 bfs, 자기 자신이 가지고 있는 숫자, 자신과 연결된 노드의 개수 - 1(루트 예외)로 나눠서 자식에게 전달
    // 자식이 없을 경우 leafNodes에 추가
    // 
    vector<double> leafNodes;
    // {노드, 가중치}
    // {1, w}
    // {int, double}
    vector<int> vis(n+1);
    queue<pid> Q;
    Q.push({1, w});
    vis[1] = 1;
    while (Q.size()) {
        // 현재 노드로부터 자식노드로 전파,
        int now = Q.front().X;
        double weight = Q.front().Y;
        Q.pop();
        // graph[now].size()
        if (now != 1) {
            // now가 root node가 아닐 때,
            // root node는 leaf가 될 수 없음
            // graph[now].size() == 1
            if (graph[now].size() == 1) {
                // leaf node
                leafNodes.push_back(weight);
                continue;
            }
        }
        // graph[now].size()-1, root -> no -1
        int dividend = graph[now].size();
        if (now != 1) dividend--;
        for (auto& next : graph[now]) {
            if (vis[next]) continue; // 부모
            // weight / dividend
            vis[next] = 1;
            Q.push({next, weight / dividend});
        }
    }
    double sum = 0;
    for (auto& e : leafNodes) sum += e;
    double avg = sum / leafNodes.size();
    cout << fixed << setprecision(10);
    cout << avg;
}