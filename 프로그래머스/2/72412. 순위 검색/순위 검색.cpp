#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;


vector<int> solution(vector<string> info, vector<string> query) {
    auto tokenize = [](string& str) {
        vector<string> ret;
        string tmp;
        for (auto& c : str) {
            if (c == ' ') {
                ret.push_back(tmp);
                tmp.clear();
            } else {
                tmp += c;
            }
        }
        ret.push_back(tmp);
        return ret;
    };
    
    // vector<int> v[4][3][3][3];
    // unordered_map<string, int> language = {{"cpp", 0}, {"java", 1}, {"python", 2}, {"-", 3}};
    // unordered_map<string, int> field = {{"backend", 0}, {"frontend", 1}, {"-", 2}};
    // unordered_map<string, int> experience = {{"junior", 0}, {"senior", 1}, {"-", 2}};
    // unordered_map<string, int> food = {{"chicken", 0}, {"pizza", 1}, {"-", 2}};
    // for (auto& e : info) {
    //     vector<string> tokens = tokenize(e);
    //     int a = language[tokens[0]];
    //     int b = field[tokens[1]];
    //     int c = experience[tokens[2]];
    //     int d = food[tokens[3]];
    //     int score = stoi(tokens[4]);
    //     for (int i = 0; i < (1 << 4); ++i) {
    //         int aa = a;
    //         int bb = b;
    //         int cc = c;
    //         int dd = d;
    //         for (int j = 0; j < 4; ++j) {
    //             if (i & (1 << j)) {
    //                 if (j == 0) aa = 3;
    //                 else if (j == 1) bb = 2;
    //                 else if (j == 2) cc = 2;
    //                 else dd = 2;
    //             }
    //         }
    //         v[aa][bb][cc][dd].push_back(score);
    //     }
    // }
    // for (int i = 0; i < 4; ++i) {
    //     for (int j = 0; j < 3; ++j) {
    //         for (int a = 0; a < 3; ++a) {
    //             for (int b = 0; b < 3; ++b) {
    //                 sort(all(v[i][j][a][b]));
    //             }
    //         }
    //     }
    // }
    // vector<int> ans;
    // for (auto& q : query) {
    //     vector<string> tokens = tokenize(q);
    //     int a = language[tokens[0]];
    //     int b = field[tokens[2]];
    //     int c = experience[tokens[4]];
    //     int d = food[tokens[6]];
    //     int score = stoi(tokens[7]);
    //     int idx = lower_bound(all(v[a][b][c][d]), score) - v[a][b][c][d].begin();
    //     ans.push_back(v[a][b][c][d].size() - idx);
    // }
    // return ans;
    
    vector<int> ans;
    unordered_map<string, vector<int>> mp;
    for (auto& e : info) {
        vector<string> tokens = tokenize(e);
        int score = stoi(tokens[4]);
        for (int i = 0; i < (1 << 4); ++i) {
            string tmp;
            for (int j = 0; j < 4; ++j) {
                if (i & (1 << j)) {
                    tmp += "-";
                } else {
                    tmp += tokens[j];
                }
            }
            mp[tmp].push_back(score);
        }
    }
    for (auto& [a, b] : mp) {
        sort(all(b));
    }
    for (auto& q : query) {
        vector<string> tokens = tokenize(q);
        string tmp;
        for (int i = 0; i < 8; i += 2) {
            tmp += tokens[i];
        }
        int score = stoi(tokens[7]);
        int idx = lower_bound(all(mp[tmp]), score) - mp[tmp].begin();
        ans.push_back(mp[tmp].size() - idx);
    }
    return ans;
}