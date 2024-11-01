#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

const int MAX = 1'000'000;
vector<int> tree;
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

int query(int node, int start, int end, int x) {
    if (start == end) return end;
    if (x > tree[node*2]) return query(node*2+1, (start+end)/2+1, end, x-tree[node*2]);
    else return query(node*2, start, (start+end)/2, x);
}

int main() {
    fastio;

    int n;
    cin >> n;
    tree.resize(MAX*4);
    while (n--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x;
            cin >> x;
            int t = query(1, 1, MAX, x);
            update(1, 1, MAX, t, -1);
            cout << t << '\n';
        } else {
            int a, b;
            cin >> a >> b;
            update(1, 1, MAX, a, b);
        }
    }
}