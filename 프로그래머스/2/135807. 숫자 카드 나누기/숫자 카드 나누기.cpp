#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> arrayA, vector<int> arrayB) {
    // 한 배열에서 최대공약수 구하기
    // 최대공약수의 약수 구하기
    // 약수들에 대해 다른 배열에서 나눠보기
    
    // 1
    auto getGCD = [](vector<int>& arr) {
        if (arr.size() == 1) return arr[0];
        else {
            int GCD = gcd(arr[0], arr[1]);
            for (int i = 2; i < arr.size(); ++i) GCD = gcd(GCD, arr[i]);
            return GCD;
        }
    };
    
    // 2
    auto getDivisors = [](int x) {
        vector<int> divisors;
        for (int i = 1; i*i <= x; ++i) {
            if (x % i) continue;
            divisors.push_back(i);
            if (i*i == x) continue;
            divisors.push_back(x/i);
        }
        sort(divisors.rbegin(), divisors.rend());
        return divisors;
    };
    
    auto getMaxA = [](vector<int>& arr, vector<int>& divisors) {
        for (auto& d : divisors) {
            bool flag = true;
            for (auto& e : arr) {
                if (e % d == 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) return d;
        }
        return 0;
    };
    
    int GCD1 = getGCD(arrayA);
    vector<int> divisors1 = getDivisors(GCD1);
    int GCD2 = getGCD(arrayB);
    vector<int> divisors2 = getDivisors(GCD2);
    int ans = max(getMaxA(arrayB, divisors1), getMaxA(arrayA, divisors2));
    return ans;
}