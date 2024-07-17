#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

void init(vector<ll>& v, vector<ll>& tree, int node, int start, int end) {
    if (start == end) {
        tree[node] = v[start];
        return;
    }
    init(v, tree, node*2, start, (start+end)/2);
    init(v, tree, node*2+1, (start+end)/2+1, end);
    tree[node] = tree[node*2] + tree[node*2+1];
}

void update_lazy(vector<ll>& tree, vector<pll>& lazy, int node, int start, int end) {
//    cout << "update_lazy " << start << ' ' << end << '\n';
//    cout << "lazy " << lazy[node].first << ' ' << lazy[node].second << '\n';
    if (lazy[node].second) {
        ll l = end - start + 1; // 구간의 길이
        tree[node] += lazy[node].first * l + (l*(l+1)/2) * lazy[node].second;
        if (start != end) {
            lazy[node*2].first += lazy[node].first;
            lazy[node*2].second += lazy[node].second;
            lazy[node*2+1].first += lazy[node].first + ((end-start) / 2 + 1) * lazy[node].second;
            lazy[node*2+1].second += lazy[node].second;
        }
        lazy[node] = {0, 0}; // 해당 구간에 대한 계산을 완료 + 자식 lazy노드로 전파 완료했으므로,
    }
}

void update_range(vector<ll>& tree, vector<pll>& lazy, int node, int start, int end, int left, int right) {
    // lazy = {높이, 카운트}
    // h = 등차수열의 첫 항
//    cout << "update_range " << start << ' ' << end << '\n';
    update_lazy(tree, lazy, node, start, end);
    if (right < start || end < left) return; // 범위에 '완전히' 포함되지 않을 경우
    if (left <= start && end <= right) {
        ll l = end - start + 1;
        tree[node] += (start-left) * l + (l*(l+1)/2);
        if (start != end) {
            lazy[node*2].first += start-left;
            lazy[node*2].second++;
            lazy[node*2+1].first += (start+end)/2 + 1 - left;
            lazy[node*2+1].second++;
        }
        return;
    }
    update_range(tree, lazy, node*2, start, (start+end)/2, left, right);
    update_range(tree, lazy, node*2+1, (start+end)/2+1, end, left, right);
    tree[node] = tree[node*2] + tree[node*2+1];
}

ll query(vector<ll>& tree, vector<pll>& lazy, int node, int start, int end, int left, int right) {
//    cout << "query " << start << ' ' << end << '\n';
    update_lazy(tree, lazy, node, start, end);
    if (left <= start && end <= right) return tree[node];
    if (end < left || start > right) return 0;
    ll lSum = query(tree, lazy, node*2, start, (start+end)/2, left, right);
    ll rSum = query(tree, lazy, node*2+1, (start+end)/2+1, end, left, right);
    return lSum + rSum;
}

int main() {
    fastio;

    int n;
    cin >> n;
    vector<ll> v(n+1);
    vector<ll> tree(n*4);
    vector<pll> lazy(n*4);
    for (int i = 1; i <= n; ++i) cin >> v[i];
    init(v, tree, 1, 1, n);
    int q;
    cin >> q;
    while (q--) {
        int a; // naming
        cin >> a;
        if (a == 1) {
            // range update
            int b, c;
            cin >> b >> c;
            update_range(tree, lazy, 1, 1, n, b, c);
        } else {
            int x;
            cin >> x;
            cout << query(tree, lazy, 1, 1, n, x, x) << '\n';
        }
    }
}