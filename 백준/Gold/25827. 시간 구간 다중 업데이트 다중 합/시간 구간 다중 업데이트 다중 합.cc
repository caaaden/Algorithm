#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;

int main() {
    fastio;

    // imos + 시간 구현
    vector<ll> v(86500); // 86400, array?
    int n;
    cin >> n;
    auto convertToSeconds = [](const string& t) {
        int seconds = 0;
        seconds += stoi(t.substr(0, 2)) * 3600;
        seconds += stoi(t.substr(3, 2)) * 60;
        seconds += stoi(t.substr(6, 2));
        return seconds;
    };
    bool flag = true;
    while (n--) {
        int c;
        cin >> c;
        if (c == 1) {
            string a, b;
            cin >> a >> b;
            int s = convertToSeconds(a);
            int e = convertToSeconds(b);
            v[s]++;
            v[e]--;
        } else {
            if (flag) {
                flag = false;
                for (int i = 1; i < 86500; ++i) {
                    v[i] += v[i-1];
                }
                for (int i = 1; i < 86500; ++i) {
                    v[i] += v[i-1];
                }
            }
            string a, b;
            cin >> a >> b;
            int s = convertToSeconds(a);
            int e = convertToSeconds(b);
            cout << v[e-1] - (s ? v[s-1] : 0) << '\n';
        }
    }
}