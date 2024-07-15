#include <bits/stdc++.h>
using namespace std;
int l, c;
vector<char> a;
vector<char> b;
// a t c i s w
// a c i s t w 
// 

void dfs(int n) {
    if (b.size() == l) {
        // 조건 확인
        // a t c i
        int cntV = 0; // 모음의 갯수
        int cntC = 0; // 자음의 갯수
        for (int i = 0; i < l; ++i) {
            // b의 원소 n개에 대해,
            if (b[i] == 'a' || b[i] == 'e' || b[i] == 'i' || b[i] == 'o' || b[i] == 'u') {
                // 모음이면,
                cntV++; // 모음의 개수 +1
            }
        }
        cntC = l - cntV; // 전체 갯수 - 모음 갯수 = 자음 갯수
        if (cntV >= 1 && cntC >= 2) {
            for (int i = 0; i < l; ++i) {
                cout << b[i];
            }
            cout << '\n';
        }
        return;
    }
    
    for (int i = n; i < c; ++i) {
        b.push_back(a[i]);
        dfs(i + 1);
        b.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // L
    // 모음 1, 자음 2
    // 정렬
    // C개 중 L개 
    cin >> l >> c;
    for (int i = 0; i < c; ++i) {
        char x;
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    dfs(0);
}