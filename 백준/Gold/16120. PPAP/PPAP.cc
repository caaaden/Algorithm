#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string str;
    cin >> str;
    stack<char> s;
    for (int i = 0; i < str.size(); ++i) {
        while (s.size() >= 4) {
            string tmp = "";
            for (int j = 0; j < 4; ++j) {
                tmp += s.top(); // string += char ?
                s.pop();
            }
            if (tmp == "PAPP") {
                s.push('P');
            } else {
                for (int j = 0; j < 4; ++j) {
                    s.push(tmp.back()); //
                    tmp.pop_back();
                }
                break;
            }
        }
        s.push(str[i]);
    }
    if (s.size() >= 4) {
        string tmp = "";
        for (int j = 0; j < 4; ++j) {
            tmp += s.top(); // string += char ?
            s.pop();
        }
        if (tmp == "PAPP") {
            s.push('P');
        } else {
            for (int j = 0; j < 4; ++j) {
                s.push(tmp.back()); //
                tmp.pop_back();
            }
        }
    }
    if (s.size() == 1 && s.top() == 'P') {
        cout << "PPAP";
    } else {
        cout << "NP";
    }
}