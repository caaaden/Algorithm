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

int main() {
    fastio;

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> JIdx, OIdx, IIdx;
    for (int i = 0; i < n; ++i) {
        // s[i]
        // J, O, I의 인덱스를 각각 저장
        if (s[i] == 'J') {
            JIdx.push_back(i);
        } else if (s[i] == 'O') {
            OIdx.push_back(i);
        } else {
            IIdx.push_back(i);
        }
    }
    // O 맨 앞 k개를 우선 선택
    // k개가 안되면? 당연히 정답 없음
    // OIdx.size() < k
    if (JIdx.size() < k || OIdx.size() < k || IIdx.size() < k) {
        cout << -1;
        return 0;
    }
    // 0, k-1
    // OIdx[0], OIdx[k-1]
    // k = 3, OIdx.size = 5
    // OIdx.size() - k + 1
    int ans = n+1;
    for (int i = 0; i < OIdx.size()-k+1; ++i) {
        // i, i+k-1
        // OIdx[i], OIdx[i+k-1]
        // 양 끝 O
        // OIdx[i]보다 작은 값 중 최대 인덱스를 JIdx에서 찾기
        // x보다 작은 값 중 최대
        // lower_bound - 1
        int a = lower_bound(all(JIdx), OIdx[i]) - JIdx.begin() - 1;
        // OIdx[i+k-1]보다 큰 값 중 최소 인덱스 = upper bound
        int b = upper_bound(all(IIdx), OIdx[i+k-1]) - IIdx.begin();
        // b부터 k개
        // b ... b+k-1
        // b+k-1 < IIdx.size()

        // a를 포함해 아래로 k개 찾기
        // a = 5, k = 3
        // a-k+1 ~ a
        // a-k+1 >= 0
        if (a-k+1 < 0 || b+k-1 >= IIdx.size()) continue;
        // J와 I k개 보장
        // JIdx[a-k+1] : J k개 중 맨 앞에 있는 값의 위치
        // IIdx[b+k-1] : I k개 중 맨 뒤에 있는 값의 위치
        // e - s + 1
        ans = min(ans, IIdx[b+k-1] - JIdx[a-k+1] + 1);
    }
    // ans - 3k
    if (ans == n+1) {
        // 각각의 개수가 k개 이상이지만 가능한 경우가 없음
        cout << -1;
        return 0;
    }
    ans -= 3 * k;
    cout << ans;
}