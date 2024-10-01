#include <bits/stdc++.h>
using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<int> v;
    v.reserve(300);
    v.push_back(k);
    while (v.back() != 1) {
        if (~v.back() & 1) {
            v.push_back(v.back() >> 1);
        } else {
            v.push_back(v.back() * 3 + 1);
        }
    }
    int n = v.size();
    vector<double> res;
    for (auto& range : ranges) {
        int a = range[0], b = range[1];
        double area = 0;
        for (int i = a; i < n+b-1; ++i) {
            area += (double)min(v[i], v[i+1]) + (double)abs(v[i] - v[i+1]) / 2;
        }
        if (a > n+b-1) res.push_back(-1);
        else res.push_back(area);
    }
    return res;
}