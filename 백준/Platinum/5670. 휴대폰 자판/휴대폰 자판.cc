#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

struct TrieNode {
    TrieNode* child[26];
    bool wordEnd;
    int numOfChild;
    TrieNode() {
        wordEnd = false;
        numOfChild = 0;
        for (int i = 0; i < 26; ++i) child[i] = nullptr;
    }

    ~TrieNode() {
        for (int i = 0; i < 26; ++i) if (child[i]) delete child[i];
    }
};

void insert(TrieNode* root, string& str) {
    TrieNode* cur = root;
    for (auto& c : str) {
        if (cur->child[c-'a'] == nullptr) {
            cur->child[c-'a'] = new TrieNode();
            cur->numOfChild++;
        }
        cur = cur->child[c-'a'];
    }
    cur->wordEnd = true;
}

int count2(TrieNode* root, string& str) {
    TrieNode* cur = root->child[str[0]-'a'];
    int cnt = 1;
    for (int i = 1; i < str.size(); ++i) {
        // 자식이 여러명일 때 : cnt++
        // 자식이 한 명일 때 : do nothing
        // 자식이 없을 때 : do nothing
        if (cur->numOfChild > 1 || cur->wordEnd) cnt++;
        cur = cur->child[str[i]-'a'];
    }
    return cnt;
}

int main() {
    fastio;

    int n;
    while (cin >> n) {
        TrieNode* root = new TrieNode();
        vector<string> strs(n);
        for (int i = 0; i < n; ++i) {
            cin >> strs[i];
            insert(root, strs[i]);
        }
        int cnt = 0;
        for (auto& s : strs) cnt += count2(root, s);
        cout << fixed;
        cout.precision(2);
        cout << (double)cnt / n << '\n';
        delete root;
    }
}