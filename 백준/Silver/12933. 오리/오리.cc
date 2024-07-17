#include <bits/stdc++.h>
using namespace std;

int cntQ, cntU, cntA, cntC, cntK, ans;

bool check() {
    return cntQ >= cntU && cntU >= cntA && cntA >= cntC && cntC >= cntK;
}

bool check2() {
    return cntQ || cntU || cntA || cntC || cntK;
}

void decCnts() {
    if (cntQ > 0 && cntU > 0 && cntA > 0 && cntC > 0 && cntK > 0) {
        cntQ--;
        cntU--;
        cntA--;
        cntC--;
        cntK--;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'q') cntQ++;
        else if (s[i] == 'u') cntU++;
        else if (s[i] == 'a') cntA++;
        else if (s[i] == 'c') cntC++;
        else cntK++;
        if (!check()) {
            cout << -1;
            return 0;
        }
        ans = max({ans, cntQ, cntU, cntA, cntC, cntK});
        decCnts();
    }
    if (check2()) {
        cout << -1;
        return 0;
    }
    cout << ans;
}