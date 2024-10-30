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

    rope<int> r;
    int n;
    cin >> n;
    vector<int> order(n);
    for (auto& e : order) cin >> e;
    for (int i = n-1; i >= 0; --i) r.insert(order[i], i+1);
    for (auto e : r) cout << e << '\n';
}