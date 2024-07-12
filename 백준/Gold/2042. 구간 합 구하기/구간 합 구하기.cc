#include <bits/stdc++.h>
using namespace std;

long long sum(vector<long long> &tree, int i) {
    long long ans = 0;
    while (i > 0) {
        ans += tree[i];
        i -= (i & -i);
    }
    return ans;
}
void update(vector<long long> &tree, int i, long long diff) {
    while (i < tree.size()) {
        tree[i] += diff;
        i += (i & -i);
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<long long> v(n+1);
    vector<long long> tree(n+1);
    
    for (int i=1; i<=n; i++) {
        cin >> v[i];
        update(tree, i, v[i]);
    }
    m += k;
    while (m--) {
        int a;
        cin >> a;
        if (a == 1) {
            int b;
            long long c;
            cin >> b >> c;
            long long diff = c-v[b];
            v[b] = c;
            update(tree, b, diff);
        } else {
            int b,c;
            cin >> b >> c;
            cout << sum(tree, c) - sum(tree, b-1) << '\n';
        }
    }
}