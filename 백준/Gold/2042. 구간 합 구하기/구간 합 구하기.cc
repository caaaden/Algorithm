#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void init(vector<ll>& v, vector<ll>& tree, int node, int start, int end) {
    if (start == end) {
        tree[node] = v[start];
        return;
    }
    init(v, tree, node*2, start, (start+end)/2);
    init(v, tree, node*2+1, (start+end)/2+1, end);
    tree[node] = tree[node*2] + tree[node*2+1];
}

void update(vector<ll>& v, vector<ll>& tree, int node, int start, int end, int index, ll val) {
    if (index < start || index > end) return;
    if (start == end) {
        v[index] = val;
        tree[node] = val;
        return;
    }
    update(v, tree, node*2, start, (start+end)/2, index, val);
    update(v, tree, node*2+1, (start+end)/2+1, end, index, val);
    tree[node] = tree[node*2] + tree[node*2+1];
}

ll query(vector<ll>& tree, int node, int start, int end, int left, int right) {
    if (left <= start && end <= right) return tree[node];
    if (end < left || start > right) return 0;
    ll lSum = query(tree, node*2, start, (start+end)/2, left, right);
    ll rSum = query(tree, node*2+1, (start+end)/2+1, end, left, right);
    return lSum + rSum;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> v(n+1);
    vector<ll> tree(n*4);
    for (int i = 1; i <= n; ++i) cin >> v[i];
    init(v, tree, 1, 1, n);
    m += k;
    while (m--) {
        int a;
        cin >> a;
        if (a == 1) {
            int b;
            ll c;
            cin >> b >> c;
            update(v, tree, 1, 1, n, b, c);
        } else {
            int b, c;
            cin >> b >> c;
            cout << query(tree, 1, 1, n, b, c) << '\n';
        }
    }
}