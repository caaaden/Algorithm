#include <bits/stdc++.h>
#include <ext/rope>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using namespace __gnu_cxx;

int main() {
    fastio;

    int t;
    cin >> t;
    vector<crope> v;
    int d = 0;
    for (int i = 0; i < t; ++i) {
        int op;
        cin >> op;
        if (op == 1) {
            int p;
            string s;
            cin >> p >> s;
            p -= d;
            crope r(s.c_str());
            if (v.size()) {
                crope r2 = v.back();
                r2.insert(p, r);
                v.push_back(r2);
            } else {
                v.push_back(r);
            }
        } else if (op == 2) {
            int p, c;
            cin >> p >> c;
            p -= d;
            c -= d;
            crope tmp = v.back();
            tmp.erase(p-1, c);
            v.push_back(tmp);
        } else {
            int v2, p, c;
            cin >> v2 >> p >> c;
            v2 -= d;
            p -= d;
            c -= d;
            crope tmp = v[v2-1].substr(p-1, c);
            for (auto e : tmp) {
                if (e == 'c') d++;
                cout << e;
            }
            cout << '\n';
        }
    }
}