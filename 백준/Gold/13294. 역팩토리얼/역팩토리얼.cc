#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main() {
    fastio;
    
    string n;
    cin >> n;
    int sz = n.size();
    if (sz == 1) {
        if (n == "1") cout << 1;
        else if (n == "2") cout << 2;
        else cout << 3;
    } else if (sz == 2) {
        cout << 4;
    } else if (sz == 3) {
        if (n == "120") cout << 5;
        else cout << 6;
    } else {
        double d = 0;
        for (int i = 1; ; ++i) {
            d += log10(i);
            if ((int)d + 1 == sz) {
                cout << i;
                return 0;
            }
        }
    }
}