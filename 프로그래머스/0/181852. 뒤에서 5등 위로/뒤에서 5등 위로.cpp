#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> num_list) {
    sort(num_list.begin(), num_list.end());
    vector<int> ret;
    ret.reserve(num_list.size()-5);
    for (int i = 5; i < num_list.size(); ++i) ret.push_back(num_list[i]);
    return ret;
}