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
    vector<int> v(n);
    for (auto& e : v) cin >> e;
    vector<int> vSorted = v;
    sort(rall(vSorted));
    vector<int> st1, st2;
    st1 = v;
    vector<pii> ans;
    for (auto& disk : vSorted) {
        // stick[1]에서 disk를 찾는다.
        // 찾았을 경우 stick[2]에 있는 원판들을
        // 다시 stick[1]으로 옮긴다.
        // 위를 반복한다.
        while (st1.size()) {
            if (st1.back() == disk) {
                st1.pop_back();
                ans.push_back({1, 3});
                break;
            } else {
                st2.push_back(st1.back());
                st1.pop_back();
                ans.push_back({1, 2});
            }
        }
        // 2에서 1로 옮기기
        while (st2.size()) {
            st1.push_back(st2.back());
            st2.pop_back();
            ans.push_back({2, 1});
        }
    }
    cout << ans.size() << '\n';
    for (auto& [a, b] : ans) cout << a << ' ' << b << '\n';
}