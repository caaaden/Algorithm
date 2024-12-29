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

    int n;
    cin >> n;
    string s;
    cin >> s;
    string t = s;
    int cnt = 0;
    // t : 이어붙일 문자열, s : 원본
    for (int i = 0; i < n; ++i) {
        // i...t.size()-1 == s ?
        // 2...5 : 2, 5-2+1
        // i, t.size()-i
        bool flag = true;
        for (int j = 0; j < n; ++j) {
            if (j+i < t.size() && s[j] == t[j+i]) continue;
            if (j+i >= t.size()) {
                t += s[j];
                continue;
            }
            flag = false;
            break;
        }
        if (flag) cnt++;
    }
    cout << cnt;
}