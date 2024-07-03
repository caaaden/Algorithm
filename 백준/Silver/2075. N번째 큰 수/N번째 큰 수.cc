#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> v[j][i];
        }
    }
    for (int i = 0; i < n-1; ++i) {
        int mmax = INT_MIN;
        int idx;
        for (int j = 0; j < n; ++j) {
            if (mmax < v[j].back()) {
                mmax = v[j].back();
                idx = j;
            }
        }
        v[idx].pop_back();
    }
    int realMax = INT_MIN;
    for (int i = 0; i < n; ++i) {
        realMax = max(realMax, v[i].back());
    }
    cout << realMax;
}