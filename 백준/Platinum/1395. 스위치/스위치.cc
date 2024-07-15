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
    tree[node] = tree[node*2] + tree[node*2+1];
}

void update_lazy(vector<ll>& tree, vector<ll>& lazy, int node, int start, int end) {
    if (lazy[node]) {
        tree[node] = (end-start+1) - tree[node];
        if (start != end) {
            lazy[node*2] = !lazy[node*2];
            lazy[node*2+1] = !lazy[node*2+1];
        }
        lazy[node] = 0;
    }
}

void update_range(vector<ll>& tree, vector<ll>& lazy, int node, int start, int end, int left, int right) {
    update_lazy(tree, lazy, node, start, end);
    if (right < start || end < left) return; // 범위에 '완전히' 포함되지 않을 경우
    if (left <= start && end <= right) {
        // tree[node] = (end-start+1) - tree[node]
        // lazy[node] = 현재 구간의 노드들을 반전시켜야 하는 지 여부
        // lazy[node*2] = !lazy[node*2]
        tree[node] = (end-start+1) - tree[node];
        if (start != end) {
            lazy[node*2] = !lazy[node*2];
            lazy[node*2+1] = !lazy[node*2+1];
        }
        return;
    }
    update_range(tree, lazy, node*2, start, (start+end)/2, left, right);
    update_range(tree, lazy, node*2+1, (start+end)/2+1, end, left, right);
    tree[node] = tree[node*2] + tree[node*2+1];
}

ll query(vector<ll>& tree, vector<ll>& lazy, int node, int start, int end, int left, int right) {
    // left ~ right에 있는 1의 개수를 return
    // tree[node] : 현재 구간에 포함된 1의 개수
    update_lazy(tree, lazy, node, start, end);
    if (left <= start && end <= right) return tree[node];
    if (end < left || start > right) return 0;
    ll lSum = query(tree, lazy, node*2, start, (start+end)/2, left, right);
    ll rSum = query(tree, lazy, node*2+1, (start+end)/2+1, end, left, right);
    return lSum + rSum;
}

int main() {
    fastio;

    int n, m;
    cin >> n >> m;
    vector<ll> tree(n*4);
    vector<ll> lazy(n*4);
    while (m--) {
        int a;
        cin >> a;
        if (!a) {
            int b, c;
            cin >> b >> c;
            update_range(tree, lazy, 1, 1, n, b, c);
        } else {
            int b, c;
            cin >> b >> c;
            cout << query(tree, lazy, 1, 1, n, b, c) << '\n';
        }
    }
}