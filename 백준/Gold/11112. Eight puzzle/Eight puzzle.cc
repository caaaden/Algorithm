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
    
    string finalState = "12345678#";
    unordered_map<string, int> dist;
    dist.insert({finalState, 0});
    queue<string> Q;
    Q.push(finalState);

    auto getEmptyPos = [](const string& state) {
        for (int i = 0; i < 9; ++i) {
            if (state[i] == '#') {
                return make_pair(i/3, i%3);
            }
        }
        return make_pair(0, 0);
    };

    while (Q.size()) {
        string now = Q.front();
        Q.pop();
        auto [ex, ey] = getEmptyPos(now); // 빈 공간의 위치 찾기
        for (int i = 0; i < 4; ++i) {
            int nx = ex + dx[i];
            int ny = ey + dy[i];
            int nowPos = ex * 3 + ey;
            int nextPos = nx * 3 + ny;
            if (nx < 0 || nx > 2 || ny < 0 || ny > 2) continue;
            string next = now;
            swap(next[nowPos], next[nextPos]);
            if (dist.count(next)) continue; // 방문 여부
            dist.insert({next, dist[now]+1});
            Q.push(next);
        }
    }

    int t; cin >> t;
    while (t--) {
        string tmp, s;
        for (int i = 0; i < 3; ++i) {
            cin >> tmp;
            s += tmp;
        }
        if (dist.count(s)) {
            cout << dist[s] << endl;
        } else {
            cout << "impossible" << endl;
        }
    }
}