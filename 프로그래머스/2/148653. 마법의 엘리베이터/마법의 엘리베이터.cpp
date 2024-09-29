#include <bits/stdc++.h>
using namespace std;

int func(int num) {
    if (num <= 1) return num;
    int x = num % 10;
    int y = num / 10;
    return min(x + func(y), 10-x + func(y+1));
    // x = 1, y = 0
}

int solution(int storey) {
    return func(storey);
}