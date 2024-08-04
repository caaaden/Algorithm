#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main() {
    fastio;

    int t;
    cin >> t;
    while (t--) {
        string a, b;
        cin >> a >> b;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        while (a.size() && a.back() == '0') a.pop_back();
        while (b.size() && b.back() == '0') b.pop_back();
        if (a.size() < b.size()) swap(a, b);
        int carry = 0;
        string ans;
        for (int i = 0; i < a.size(); ++i) {
            int sum = (a[i] - '0') + carry;
            if (i < b.size()) sum += b[i] - '0';
            carry = sum / 2;
            ans += (sum % 2) + '0';
        }
        if (carry) ans += '1';
        reverse(ans.begin(), ans.end());
        if (ans.empty()) cout << 0 << '\n';
        else cout << ans << '\n';
    }
}