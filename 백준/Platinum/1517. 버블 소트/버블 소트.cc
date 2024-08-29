#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll merge(vector<int> &v, int p, int q, int r) {
    vector<int> tmp(r - p + 1);
    int i = p, j = q + 1, t = 0;
    ll cnt = 0;
    while (i <= q && j <= r) {
        if (v[i] <= v[j]) tmp[t++] = v[i++];
        else {
            tmp[t++] = v[j++];
            cnt += q+1-i;
        }
    }
    while (i <= q) tmp[t++] = v[i++];
    while (j <= r) tmp[t++] = v[j++];
    i = p, t = 0;
    while (i <= r) v[i++] = tmp[t++];
    return cnt;
}

ll mergeSort(vector<int> &v, int p, int r) {
    ll cnt = 0;
    if (p < r) {
        int q = (p + r) / 2;
        cnt += mergeSort(v, p, q);
        cnt += mergeSort(v, q + 1, r);
        cnt += merge(v, p, q, r);
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &e: v) cin >> e;
    cout << mergeSort(v, 0, n - 1);
}