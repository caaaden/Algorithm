#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, k;
vector<int> tree;
void init(int node, int start, int end) {
    if (start == end) {
        tree[node] = 1;
        return;
    }
    int mid = (start + end) / 2;
    init(node*2, start, mid);
    init(node*2+1, mid+1, end);
    tree[node] = tree[node*2] + tree[node*2+1];
}

void update(int node, int start, int end, int index, int val) {
    if (index < start || index > end) return;
    if (start == end) {
        tree[node] += val;
        return;
    }
    update(node*2, start, (start+end)/2, index, val);
    update(node*2+1, (start+end)/2+1, end, index, val);
    tree[node] = tree[node*2] + tree[node*2+1];
}

int query(int node, int start, int end, int idx) {
    tree[node]--;
    if (start == end) return end;
    if (idx > tree[node*2]) return query(node*2+1, (start+end)/2+1, end, idx-tree[node*2]);
    else return query(node*2, start, (start+end)/2, idx);
}

int main() {
    fastio;

    cin >> n >> k;
    tree.resize(n*4);
    init(1, 1, n);
    string ans = "<";
    int idx = 0;
    for (int i = 0; i < n-1; ++i) {
        idx += k - 1;
        idx %= tree[1];
        ans += to_string(query(1, 1, n, idx+1));
        ans += ", ";
    }
    idx += k - 1;
    idx %= tree[1];
    ans += to_string(query(1, 1, n, idx+1));
    ans += '>';
    cout << ans;
}