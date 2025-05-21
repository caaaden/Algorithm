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

    // 순환 전 숫자 길이 구하기 = x
    // 순환 소수 길이 구하기 = y
    // 0.25(75)
    // x = 2
    // y = 2
    // 10^(x+y) - 10^x = 분모
    // 순환 전 숫자 = a
    // 순환 소수 = b
    // a | b를 a와 b 숫자를 잇는 표현이라고 가정하면
    // (a | b) - a
    // 2575 - 25 = 2550

    auto powerOf10 = [](int x) {
        int ret = 1;
        for (int i = 0; i < x; ++i) ret *= 10;
        return ret;
    };

    string s;
    while (cin >> s) {
        int idx = s.find('.');
        int idx2 = s.find('(');
        int idx3 = s.find(')');
        // idx2 - idx - 1
        int x = idx2 - idx - 1;
        // idx3 - idx2 - 1
        int y = idx3 - idx2 - 1;
        // x + y
        int den = powerOf10(x+y) - powerOf10(x);
        // s.substr(0, idx) + s.substr(idx+1, idx2-idx-1)
        // s.substr(idx2+1, idx3-idx2-1)
        string a = s.substr(0, idx) + s.substr(idx+1, idx2-idx-1);
        string b = a + s.substr(idx2+1, idx3-idx2-1);
        int num = stoi(b) - stoi(a);
        // num / den
        int GCD = gcd(num, den);
        num /= GCD;
        den /= GCD;
        cout << s << " = " << num << " / " << den << '\n';
    }
}