#include <bits/stdc++.h>
using namespace std;

int timeToSec(string t) {
    // HH:MM -> integer
    int h = (t[0] - '0') * 10 + (t[1] - '0');
    int s = (t[3] - '0') * 10 + (t[4] - '0');
    return h * 60 + s;
}

bool isIncluded(string a, string b, string x) {
    // a <= x <= b 인지 확인.
    int tmp = timeToSec(x);
    return (timeToSec(a) <= tmp) && (tmp <= timeToSec(b));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s, e, q;
    cin >> s >> e >> q;
    set<string> s1, s2;
    string line;
    while (getline(cin, line)) {
        string t, name;
        for (int i = 0; i < 5; ++i) {
            t += line[i];
        }
        for (int i = 6; i < line.size(); ++i) {
            name += line[i];
        }
        if (isIncluded("00:00", s, t)) {
            s1.insert(name);
        }
        if (isIncluded(e, q, t)) {
            s2.insert(name);
        }
    }
    int cnt = 0;
    for (auto e : s1) {
        if (s2.find(e) != s2.end()) cnt++;
    }
    cout << cnt;
}