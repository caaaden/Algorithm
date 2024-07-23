#include <string>
#include <vector>

using namespace std;

int solution(string n_str) {
    int ret = 0;
    for (auto& c : n_str) ret += c - '0';
    return ret;
}