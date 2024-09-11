#include <bits/stdc++.h>
using namespace std;

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    // 짜증나는 구현 문제
    // 문제를 잘 읽고 풀자
    // 예시는 이해를 도울 수 있다
    
    // 현재 위치가 오프닝에 포함되는 지 확인
    // 포함된다면 오프닝의 끝으로 이동
    // command를 수행할 때마다 오프닝 포함 여부를 확인하기
    // 범위 바깥으로 벗어나는 경우 고려
    
    // MM:SS를 second로 변환해 계산 후 다시 변환
    auto timeToSec = [](string& t) {
        // 12:34
        return stoi(t.substr(0, 2)) * 60 + stoi(t.substr(3, 2));
    };
    
    auto secToTime = [](int s) {
        int m = s / 60;
        s %= 60;
        string ans;
        if (!m) ans += "00";
        else if (m < 10) ans += '0', ans += to_string(m);
        else ans += to_string(m);
        ans += ':';
        if (!s) ans += "00";
        else if (s < 10) ans += '0', ans += to_string(s);
        else ans += to_string(s);
        return ans;
    };
    
    int now = timeToSec(pos);
    int len = timeToSec(video_len);
    int s = timeToSec(op_start);
    int e = timeToSec(op_end);
    
    // 현재 위치가 오프닝에 포함된다면 끝으로
    if (s <= now && now < e) now = e;
    for (auto& command : commands) {
        if (command == "prev") {
            // 10초 전으로,
            // 만약 10초 미만이라면 0초로
            now -= 10;
            if (now < 0) now = 0;
        } else {
            // 10초 후로
            now += 10;
            // 만약 비디오 끝을 넘어갈 경우 비디오 끝으로
            if (now > len) now = len;
        }
        if (s <= now && now < e) now = e;
    }
    return secToTime(now);
}