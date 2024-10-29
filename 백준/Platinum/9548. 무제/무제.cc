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

    int t;
    cin >> t;
    while (t--) {
        string tmp;
        cin >> tmp;
        crope s;
        for (auto& c : tmp) s += c;
        string command;
        while (true) {
            cin >> command;
            if (command.size() > 1) break;
            if (command == "I") {
                int x;
                cin >> tmp >> x;
                crope r;
                for (auto& c : tmp) r += c;
                s.insert(x, r);
            } else {
                int x, y;
                cin >> x >> y;
                cout << s.substr(x, y-x+1) << '\n';
            }
        }
    }
}