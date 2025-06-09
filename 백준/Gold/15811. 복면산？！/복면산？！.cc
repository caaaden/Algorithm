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

    // ll
    // leading zero number is okay
    // SUN FUN SWIM -> YES
    // 각 변수에 가중치
    // S * 100 + U * 10 + N * 1 + F * 100 ...
    vector<string> words(3);
    for (auto& word : words) cin >> word;
    // weight
    vector<ll> coeff(26); // 각 알파벳에 가중치를 부여
    for (int i = 0; i < 3; ++i) {
        string& word = words[i];
        for (int j = word.size()-1, w = 1; j >= 0; --j, w *= 10) {
            if (i != 2) coeff[word[j]-'A'] += w;
            else coeff[word[j]-'A'] -= w;
        }
    }
    // 가중치가 있는, 즉 coeff[x] != 0인 x에 대해서만 백트래킹
    vector<ll> mult;
    for (int i = 0; i < 26; ++i) {
        if (!coeff[i]) continue;
        mult.push_back(coeff[i]);
    }
    // 0~9에서 r개만큼 뽑기(순열)
    vector<bool> used(10);
    vector<int> arr; // selected numbers
//    int ans = 0;
    function<void(int)> dfs = [&](int d) {
        if (d == mult.size()) {
            // mult[i] * arr[i]
            ll sum = 0;
            for (int i = 0; i < mult.size(); ++i) {
                sum += mult[i] * arr[i];
            }
            if (!sum) {
                cout << "YES";
                exit(0);
            }
            return;
        }
        for (int i = 0; i < 10; ++i) {
            if (used[i]) continue;
            used[i] = true;
            arr.push_back(i);
            dfs(d+1);
            arr.pop_back();
            used[i] = false;
        }
    };
    dfs(0);
//    cout << ans;
    cout << "NO";
}