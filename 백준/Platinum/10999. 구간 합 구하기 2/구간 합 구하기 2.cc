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
        tree[node] += (end-start+1) * lazy[node];
        if (start != end) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0; // 해당 구간에 대한 계산을 완료 + 자식 lazy노드로 전파 완료했으므로,
    }
}

void update_range(vector<ll>& tree, vector<ll>& lazy, int node, int start, int end, int left, int right, ll diff) {
    update_lazy(tree, lazy, node, start, end);
    if (right < start || end < left) return; // 범위에 '완전히' 포함되지 않을 경우
    if (left <= start && end <= right) {
        tree[node] += (end-start+1) * diff;
        if (start != end) {
            lazy[node*2] += diff;
            lazy[node*2+1] += diff;
        }
        return;
    }
    update_range(tree, lazy, node*2, start, (start+end)/2, left, right, diff);
    update_range(tree, lazy, node*2+1, (start+end)/2+1, end, left, right, diff);
    tree[node] = tree[node*2] + tree[node*2+1];
}

ll query(vector<ll>& tree, vector<ll>& lazy, int node, int start, int end, int left, int right) {
    update_lazy(tree, lazy, node, start, end);
    if (left <= start && end <= right) return tree[node];
    if (end < left || start > right) return 0;
    ll lSum = query(tree, lazy, node*2, start, (start+end)/2, left, right);
    ll rSum = query(tree, lazy, node*2+1, (start+end)/2+1, end, left, right);
    return lSum + rSum;
}

int main() {
    fastio;

    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> v(n+1);
    vector<ll> tree(n*4);
    vector<ll> lazy(n*4);
    for (int i = 1; i <= n; ++i) cin >> v[i];
    init(v, tree, 1, 1, n);
    m += k;
    while (m--) {
        int a;
        cin >> a;
        if (a == 1) {
            int b, c;
            ll d;
            cin >> b >> c >> d;
            update_range(tree, lazy, 1, 1, n, b, c, d);
        } else {
            int b, c;
            cin >> b >> c;
            cout << query(tree, lazy, 1, 1, n, b, c) << '\n';
        }
    }
}