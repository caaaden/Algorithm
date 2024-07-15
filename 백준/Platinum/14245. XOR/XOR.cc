#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;

void init(vector<ll>& v, vector<ll>& tree, int node, int start, int end) {
    if (start == end) {
        tree[node] = v[start];
        return;
    }
    init(v, tree, node*2, start, (start+end)/2);
    init(v, tree, node*2+1, (start+end)/2+1, end);
    tree[node] = tree[node*2] ^ tree[node*2+1];
}

void update_lazy(vector<ll>& tree, vector<ll>& lazy, int node, int start, int end) {
    if (lazy[node]) {
        // 해당 구간에 xor 해야할 값이 있다면,
        if ((end-start+1) & 1) tree[node] ^= lazy[node];
        if (start != end) {
            // 자식 lazy nodes로 전파
            lazy[node*2] ^= lazy[node];
            lazy[node*2+1] ^= lazy[node];
        }
        lazy[node] = 0;
    }
}

void update_range(vector<ll>& tree, vector<ll>& lazy, int node, int start, int end, int left, int right, int k) {
    update_lazy(tree, lazy, node, start, end);
    if (right < start || end < left) return; // 범위에 '완전히' 포함되지 않을 경우
    if (left <= start && end <= right) {
        // end-start+1 = 홀수 : k를 xor
        // = 짝수 : do nothing
        if ((end-start+1) & 1) tree[node] ^= k;
        if (start != end) {
            lazy[node*2] ^= k;
            lazy[node*2+1] ^= k;
        }
        return;
    }
    update_range(tree, lazy, node*2, start, (start+end)/2, left, right, k);
    update_range(tree, lazy, node*2+1, (start+end)/2+1, end, left, right, k);
    tree[node] = tree[node*2] ^ tree[node*2+1];
}

ll query(vector<ll>& tree, vector<ll>& lazy, int node, int start, int end, int left, int right) {
    update_lazy(tree, lazy, node, start, end);
    if (left <= start && end <= right) return tree[node];
    if (end < left || start > right) return 0;
    ll lXor = query(tree, lazy, node*2, start, (start+end)/2, left, right);
    ll rXor = query(tree, lazy, node*2+1, (start+end)/2+1, end, left, right);
    return lXor ^ rXor;
}

int main() {
    fastio;

    int n;
    cin >> n;
    vector<ll> v(n+1);
    vector<ll> tree(n*4);
    vector<ll> lazy(n*4);
    for (int i = 1; i <= n; ++i) cin >> v[i];
    init(v, tree, 1, 1, n);
    int m;
    cin >> m;
    while (m--) {
        int a;
        cin >> a;
        if (a == 1) {
            int i, j, k;
            cin >> i >> j >> k;
            update_range(tree, lazy, 1, 1, n, i+1, j+1, k);
        } else {
            int a;
            cin >> a;
            cout << query(tree, lazy, 1, 1, n, a+1, a+1) << '\n';
        }
    }
}