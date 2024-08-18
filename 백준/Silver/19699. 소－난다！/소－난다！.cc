#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int n, m;
vector<int> v;
set<int> s;
vector<bool> isPrime(9001, true);
int sum;
void dfs(int k, int idx) {
    if (k == m) {
        if (!isPrime[sum]) return;
        s.insert(sum);
        return;
    }
    for (int i = idx; i < n; ++i) {
        sum += v[i];
        dfs(k+1, i+1);
        sum -= v[i];
    }
}

int main() {
    fastio;

    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i*i <= 9000; ++i) {
        if (!isPrime[i]) continue;
        for (int j = i*i; j <= 9000; j += i) {
            isPrime[j] = false;
        }
    }
    cin >> n >> m;    
    v.resize(n);
    for (auto& e : v) cin >> e;
    dfs(0, 0);
    if (s.empty()) {
        cout << -1;
    } else {
        for (auto& e : s) cout << e << ' ';    
    }
}