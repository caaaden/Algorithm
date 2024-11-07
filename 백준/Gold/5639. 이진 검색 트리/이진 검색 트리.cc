#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0);
#define all(v) v.begin(), v.end()
#define X first
#define Y second
using namespace std;
using ll = long long;

int main() {
    fastio;

    vector<int> v;
    v.reserve(10000);
    int x;
    while (cin >> x) v.push_back(x);
    function<void(int, int)> traversal = [&](int s, int e) {
        if (s == e) return;
        if (s+1 == e) {
            cout << v[s] << '\n';
            return;
        } 
        int i = lower_bound(v.begin()+s+1, v.begin()+e, v[s]) - v.begin();
        traversal(s+1, i);
        traversal(i, e);
        cout << v[s] << '\n';
    };
    traversal(0, v.size());
}