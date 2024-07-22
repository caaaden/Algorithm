#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastio;

    // 감추어진 가로 줄까지 각각 위, 아래에서 탐색 진행.
    // 감추어진 가로 줄 바로 위, 바로 아래에 배치된 알파벳에 따라
    // * or -를 결정.
    int k, n;
    cin >> k >> n;
    vector<int> top(k), bottom(k);
    for (int i = 0; i < k; ++i) top[i] = i;
    for (int i = 0; i < k; ++i) {
        char c;
        cin >> c;
        bottom[c - 'A'] = i;
    }
    vector<string> ladder(n);
    int hiddenLine;
    for (int i = 0; i < n; ++i) {
        cin >> ladder[i];
        if (ladder[i][0] == '?') hiddenLine = i;
    }
    // 0...i-1
    // i+1...n-1
    for (int i = 0; i < hiddenLine; ++i) {
        for (int j = 0; j < k; ++j) {
            if (top[j] == 0) {
                if (ladder[i][top[j]] == '*') continue;
                top[j]++;
            } else if (top[j] == k-1) {
                if (ladder[i][top[j]-1] == '*') continue;
                top[j]--;
            } else {
                if (ladder[i][top[j]-1] == '*' && ladder[i][top[j]] == '*') continue;
                if (ladder[i][top[j]-1] == '-') top[j]--;
                else top[j]++;
            }
        }
    }
    for (int i = n-1; i > hiddenLine; --i) {
        for (int j = 0; j < k; ++j) {
            if (bottom[j] == 0) {
                if (ladder[i][bottom[j]] == '*') continue;
                bottom[j]++;
            } else if (bottom[j] == k-1) {
                if (ladder[i][bottom[j]-1] == '*') continue;
                bottom[j]--;
            } else {
                if (ladder[i][bottom[j]-1] == '*' && ladder[i][bottom[j]] == '*') continue;
                if (ladder[i][bottom[j]-1] == '-') bottom[j]--;
                else bottom[j]++;
            }
        }
    }

//    for (int i = 0; i < k; ++i) {
//        cout << top[i] << ' ' << i << '\n';
//    }
//    cout << '\n';
//    vector<int> top2(k);
//    for (int i = 0; i < k; ++i) {
//        top2[top[i]] = i;
//    }
//
//    for (int i = 0; i < k; ++i) {
//        cout << i << ' ' << top2[i] << '\n';
//    }

    vector<int> top2(k), bottom2(k);
    for (int i = 0; i < k; ++i) {
//         알파벳 : 인덱스 -> 인덱스 : 알파벳으로 전환
        top2[top[i]] = i;
        bottom2[bottom[i]] = i;
    }

//    for (int i = 0; i < k; ++i) {
//        cout << top2[i] << ' ';
//    }
//    cout << '\n';
//    for (int i = 0; i < k; ++i) {
//        cout << bottom2[i] << ' ';
//    }
//    cout << '\n';


    string ans;
    bool flag = true;
    for (int i = 0; i < k-1; ++i) {
        if (top2[i] == bottom2[i]) {
            ans += '*';
        } else if (top2[i] == bottom2[i+1] && top2[i+1] == bottom2[i]) {
            if (i == k-2) {
                ans += '-';
            } else {
                ans += "-*";
                ++i;
            }
        } else {
            flag = false;
            break;
        }
    }
    if (flag) cout << ans;
    else {
        for (int i = 0; i < k-1; ++i) cout << 'x';
    }
//    int cnt = 0;
//    for (int i = 0; i < k-1; ++i) {
//        if (top[i] == bottom[i+1] && top[i+1] == bottom[i]) {
//            ans += "--";
//            ++i;
//        }
//        else if (top[i] == bottom[i] && top[i+1] == bottom[i+1]) {
//            ans += "**";
//            ++i;
//        }
//        else {
//            cnt++;
//        }
//    }
//    if (cnt > 1) {
//        for (int i = 0; i < k-1; ++i) cout << 'x';
//    } else cout << ans;
}