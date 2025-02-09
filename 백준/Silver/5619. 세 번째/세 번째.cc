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
const long long MOD = 1e9 + 7;

int main(){
    fastio;

    int n;
    cin >> n;
    vector<int> cnt(10001);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    priority_queue<int> pq; // 최소 숫자 3개를 저장, max heap
    // pq.top()과 비교해 더 작을 경우 pq.top()을 pop한 뒤 삽입
    // pq.size() < 3이면 우선 삽입
    auto concatenate = [](int x, int y) {
        return stoi(to_string(x) + to_string(y));
    };
    for (int i = 1; i <= 10000; ++i) {
        if (!cnt[i]) continue;
        int count = 0;
        for (int j = 1; j <= 10000 && count < 3; ++j) {
            if (!cnt[j]) continue;
            if (i == j) continue;
            count++;
            int num = concatenate(i, j);
            if (pq.size() < 3) {
                pq.push(num);
            } else {
                // pq.size() == 3
                if (pq.top() > num) {
                    pq.pop();
                    pq.push(num);
                }
            }
        }
    }
    cout << pq.top();
}