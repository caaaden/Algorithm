#include <bits/stdc++.h>
using namespace std;
int v[11];
int n;
int getMax(int i, int val, vector<int> ops) {
    if (i == n) {
        return val;
    }
    int mmax = INT_MIN;
    if (ops[0] != 0) {
        int newVal = val + v[i];
        vector<int> tmp = ops;
        tmp[0]--;
        mmax = max(mmax, getMax(i+1, newVal, tmp));
    }
    if (ops[1] != 0) {
        int newVal = val - v[i];
        vector<int> tmp = ops;
        tmp[1]--;
        mmax = max(mmax, getMax(i+1, newVal, tmp));
    }
    if (ops[2] != 0) {
        int newVal = val * v[i];
        vector<int> tmp = ops;
        tmp[2]--;
        mmax = max(mmax, getMax(i+1, newVal, tmp));
    }
    if (ops[3] != 0) {
        int newVal = val / v[i];
        vector<int> tmp = ops;
        tmp[3]--;
        mmax = max(mmax, getMax(i+1, newVal, tmp));
    }
    return mmax;
}

int getMin(int i, int val, vector<int> ops) {
    if (i == n) {
        return val;
    }
    int mmin = INT_MAX;
    if (ops[0] != 0) {
        int newVal = val + v[i];
        vector<int> tmp = ops;
        tmp[0]--;
        mmin = min(mmin, getMin(i+1, newVal, tmp));
    }
    if (ops[1] != 0) {
        int newVal = val - v[i];
        vector<int> tmp = ops;
        tmp[1]--;
        mmin = min(mmin, getMin(i+1, newVal, tmp));
    }
    if (ops[2] != 0) {
        int newVal = val * v[i];
        vector<int> tmp = ops;
        tmp[2]--;
        mmin = min(mmin, getMin(i+1, newVal, tmp));
    }
    if (ops[3] != 0) {
        int newVal = val / v[i];
        vector<int> tmp = ops;
        tmp[3]--;
        mmin = min(mmin, getMin(i+1, newVal, tmp));
    }
    return mmin;    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> v[i];
    vector<int> ops(4);
    for (int i = 0; i < 4; ++i) cin >> ops[i];
    cout << getMax(1, v[0], ops) << '\n';
    cout << getMin(1, v[0], ops);
}