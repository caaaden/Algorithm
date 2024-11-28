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

    int n, m;
    cin >> n >> m;
    vector<string> words(n);
    int totalLength = 0;
    for (auto& e : words) {
        cin >> e;
        totalLength += e.size();
    }
    int underscoreLength = m - totalLength;
    int q = underscoreLength / (n-1);
    int r = underscoreLength % (n-1);
    vector<string> newWords;
    vector<int> comb;
    for (int i = 0; i < r; ++i) comb.push_back(0);
    for (int i = 0; i < (n-1) - r; ++i) comb.push_back(1);
    do {
        string newWord;
        for (int i = 0; i < n-1; ++i) {
            newWord += words[i];
            for (int j = 0; j < q; ++j) newWord += '_';
            if (!comb[i]) newWord += '_';
        }
        newWord += words[n-1];
        newWords.push_back(newWord);
    } while (next_permutation(all(comb)));
    string ans(m, 'z');
    for (auto& e : newWords) ans = min(ans, e);
    cout << ans;
}