#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<long long> solution(vector<long long> numbers) {
    vector<ll> ans;
    ans.reserve(numbers.size());
    for (auto& num : numbers) {
        if (~num & 1) {
            ans.push_back(num + 1);
        } else {
            ll tmp = num;
            int cnt = 0;
            while (tmp & 1) {
                cnt++;
                tmp >>= 1;
            }
            ans.push_back(num + (1LL << cnt) - (1LL << (cnt-1)));
        }
    }
    return ans;
}