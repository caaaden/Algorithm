#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main() {
    fastio;

    int l;
    cin >> l;
    vector<int> v(l);
    for (auto& e : v) cin >> e;
    int n;
    cin >> n;
    sort(v.begin(), v.end());
    if (binary_search(v.begin(), v.end(), n)) {
        cout << 0;
    } else {
        int idx = lower_bound(v.begin(), v.end(), n) - v.begin();
        int a = v[idx-1];
        int b = v[idx];
        cout << (n-a) * (b-n) - 1;
    }
}