#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;

void update(vector<ll>& tree, int node, int start, int end, int index, ll val) {
    if (index < start || index > end) return;
    if (start == end) {
        tree[node] += val;
        return;
    }
    update(tree, node*2, start, (start+end)/2, index, val);
    update(tree, node*2+1, (start+end)/2+1, end, index, val);
    tree[node] = tree[node*2] + tree[node*2+1];
}

ll query(vector<ll>& tree, int node, int start, int end, int x) {
    if (start == end) return end;
    if (x > tree[node*2]) return query(tree, node*2+1, (start+end)/2+1, end, x-tree[node*2]);
    else return query(tree, node*2, start, (start+end)/2, x);
}

int main() {
    fastio;

    int n;
    cin >> n;
    const int MAX = 1'000'000;
    vector<ll> tree(MAX*4);
    while (n--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x;
            cin >> x;
            int t = query(tree, 1, 1, MAX, x);
            update(tree, 1, 1, MAX, t, -1);
            cout << t << '\n';
        } else {
            int a, b;
            cin >> a >> b;
            update(tree, 1, 1, MAX, a, b);
        }
    }
}