#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0);
#define all(v) v.begin(), v.end()
#define X first
#define Y second
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using piii = pair<int, pii>;

int main() {
    fastio;

    auto failure = [](const string& s) {
        vector<int> f(s.size());
        for (int j = 0, i = 1; i < s.size(); ++i) {
            while (j > 0 && s[i] != s[j]) j = f[j-1];
            if (s[i] == s[j]) f[i] = ++j;
        }
        return f;
    };

    string s, p;
    cin >> s >> p;
    vector<int> f = failure(p);
    for (int j = 0, i = 0; i < s.size(); ++i) {
        while (j > 0 && s[i] != p[j]) j = f[j-1];
        if (s[i] == p[j]) ++j;
        if (j == p.size()) {
            // 일치
            cout << 1;
            return 0;
        }
    }
    cout << 0;
}