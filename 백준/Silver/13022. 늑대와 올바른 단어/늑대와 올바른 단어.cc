#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main() {
    fastio;
    
    string s;
    cin >> s;
    int pos = 0;
    vector<string> tbl(13);
    for (int i = 1; i <= 12; ++i) {
        string tmp;
        for (int j = 0; j < i; ++j) tmp += 'w';
        for (int j = 0; j < i; ++j) tmp += 'o';
        for (int j = 0; j < i; ++j) tmp += 'l';
        for (int j = 0; j < i; ++j) tmp += 'f';
        tbl[i] = tmp;
    }
    while (pos < s.size()) {
        bool found = false;
        for (int i = 1; i <= 12; ++i) {
            if (pos + i*4 > s.size()) break;
            if (s.substr(pos, i*4) == tbl[i]) {
                found = true;
                pos += i*4;
                break;
            }
        }
        if (!found) {
            cout << 0;
            return 0;
        }
    }
    cout << 1;
}