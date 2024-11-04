#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastio;

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        string s2;
        for (auto& c : s) {
            s2 += c;
            int cnt = 0;
            while (s2.size() >= 3) {
                if (s2.substr(s2.size()-3) == "ABB") {
                    s2.pop_back();
                    s2.pop_back();
                    s2.pop_back();
                    s2 += 'B';
                    cnt++;
                } else break;
            }
            for (int i = 0; i < cnt; ++i) s2 += 'A';
        }
        cout << s2 << '\n';
    }
}