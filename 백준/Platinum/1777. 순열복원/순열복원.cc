#include <bits/stdc++.h>
#include <ext/rope>
#define fastio ios::sync_with_stdio(0), cin.tie(0);
#define all(v) v.begin(), v.end()
#define X first
#define Y second
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using namespace __gnu_cxx;

int main() {
    fastio;

    int n;
    cin >> n;
    rope<int> r;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        r.insert(r.size()-x, i);
    }
    for (auto e : r) cout << e << ' ';
}