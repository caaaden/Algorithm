#include <bits/stdc++.h>
#include <ext/rope>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using namespace __gnu_cxx;

int main() {
    fastio;

    string s;
    cin >> s;
    crope r(s.c_str());
    int q;
    cin >> q;
    while (q--) {
        int c;
        cin >> c;
        if (c == 1) {
            int x, y;
            cin >> x >> y;
            r = r.substr(x, y-x+1) + r.substr(0, x) + r.substr(y+1, r.size());
        } else if (c == 2) {
            int x, y;
            cin >> x >> y;
            r = r.substr(0, x) + r.substr(y+1, r.size()) + r.substr(x, y-x+1);
        } else {
            int x;
            cin >> x;
            cout << r[x] << '\n';
        }
    }
}