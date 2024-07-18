#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
using pii = pair<int, int>;

int main() {
    fastio;
    
    
    unordered_map<char, pii> lm = {{'q', {0, 0}}, {'w', {0, 1}}, {'e', {0, 2}}, {'r', {0, 3}}, {'t', {0, 4}}, {'a', {1, 0}}, {'s', {1, 1}}, {'d', {1, 2}}, {'f', {1, 3}}, {'g', {1, 4}}, {'z', {2, 0}}, {'x', {2, 1}}, {'c', {2, 2}}, {'v', {2, 3}}};
    unordered_map<char, pii> rm = {{'y', {0, 5}}, {'u', {0, 6}}, {'i', {0, 7}}, {'o', {0, 8}}, {'p', {0, 9}}, {'h', {1, 5}}, {'j', {1, 6}}, {'k', {1, 7}}, {'l', {1, 8}}, {'b', {2, 4}}, {'n', {2, 5}}, {'m', {2, 6}}};
    char a, b;
    string c;
    cin >> a >> b >> c;
    pii l = lm[a], r = rm[b];
    int ans = 0;
    for (int i = 0; i < c.size(); ++i) {
        if (lm.count(c[i])) {
            ans += abs(l.first - lm[c[i]].first) + abs(l.second - lm[c[i]].second) + 1;
            l.first = lm[c[i]].first;
            l.second = lm[c[i]].second;
        } else {
            ans += abs(r.first - rm[c[i]].first) + abs(r.second - rm[c[i]].second) + 1;
            r.first = rm[c[i]].first;
            r.second = rm[c[i]].second;
        }
    }
    cout << ans;
}