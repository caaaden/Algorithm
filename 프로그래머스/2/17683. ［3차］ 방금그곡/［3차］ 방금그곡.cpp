#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

string solution(string m, vector<string> musicinfos) {
    
    auto convertNote = [](const string& s) {    
        string ret;
        for (int i = 0; i < s.size()-1; ++i) {
            if (s[i+1] == '#') {
                if (s[i] == 'C') {
                    ret += 'H';
                } else if (s[i] == 'D') {
                    ret += 'I';
                } else if (s[i] == 'F') {
                    ret += 'J';
                } else if (s[i] == 'G') {
                    ret += 'K';
                } else {
                    ret += 'L';
                }
                ++i;
            } else {
                ret += s[i];
            }
        }
        if (s.back() != '#') ret += s.back();
        return ret;
    };
    
    auto tokenize = [](const string& s) {
        string tmp;
        vector<string> ret;
        for (auto& c : s) {
            if (c == ',') {
                ret.push_back(tmp);
                tmp.clear();
            } else {
                tmp += c;
            }
        }
        ret.push_back(tmp);
        return ret;
    };
    
    auto timeToMinutes = [](const string& time) {
        return stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2));
    };
    
    m = convertNote(m);
    int n = musicinfos.size();
    
    vector<int> check(n);
    vector<int> durations(n);
    
    for (int i = 0; i < n; ++i) {
        vector<string> tokenizedMusicinfo = tokenize(musicinfos[i]);
        
        string start = tokenizedMusicinfo[0];
        string end = tokenizedMusicinfo[1];
        
        durations[i] = timeToMinutes(end) - timeToMinutes(start);
        
        string title = tokenizedMusicinfo[2];
        string score = convertNote(tokenizedMusicinfo[3]);
        
        string musicPlayed;
        if (durations[i] < score.size()) {
            musicPlayed = score.substr(0, durations[i]);
        } else {
            for (int j = 0; j < durations[i]/score.size(); ++j) musicPlayed += score;
            musicPlayed += score.substr(0, durations[i]%score.size());
        }
        if (musicPlayed.find(m) != -1) {
            check[i] = 1;
        }
    }
    vector<pii> musics;
    for (int i = 0; i < musicinfos.size(); ++i) {
        if (check[i]) {
            musics.push_back({durations[i], i});
        }
    }
    if (musics.empty()) {
        return "(None)";
    }
    sort(musics.begin(), musics.end(), [](const pii& a, const pii& b) {
       if (a.first == b.first) return a.second < b.second;
        return a.first > b.first;
    });
    int idx = musics[0].second;
    return tokenize(musicinfos[idx])[2];
}