#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<long long> solution(vector<long long> numbers) {
    vector<ll> ans;
    ans.reserve(numbers.size());
    for (auto& num : numbers) {
        ll pow = 1;
        while (num & pow) pow <<= 1;
        ans.push_back(num + pow - (pow >> 1));
    }
    return ans;
}