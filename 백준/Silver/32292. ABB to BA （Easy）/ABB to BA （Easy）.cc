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
        string target = "ABB";
        string replacement = "BA";
        size_t pos = s.find(target);
        while (pos != -1) {
            s.replace(pos, target.size(), replacement);
            pos = s.find(target, max(0, (int)pos-2));
        }
        cout << s << '\n';
    }
}