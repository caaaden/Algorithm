#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

array<i64, 3> v;
i64 n;
vector<i64> sequence;

void getNumbers(i64 now, i64 idx) {
    if (now < 0) return;
    if (now >= 1e18) return;
    sequence.push_back(now);
    for (int i = idx; i < 3; ++i) getNumbers(now * v[i], i);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (auto& e : v) cin >> e;
    cin >> n;
    sort(v.begin(), v.end());
//    sequence.reserve(10000);
    for (int i = 0; i < 3; ++i) getNumbers(v[i], i);
    sort(sequence.begin(), sequence.end());
    cout << sequence[n-1];
}