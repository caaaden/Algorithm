//#pragma GCC optimize("O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace __gnu_pbds;
using namespace std;
using pii = pair<int, int>;
using i64 = long long;
typedef tree<i64, null_type, less_equal<i64>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<i64, null_type, greater_equal<i64>, rb_tree_tag, tree_order_statistics_node_update> ordered_set2;

int main() {
    fastio;

    // s개를 고른다
    // 하나씩 삽입하며 order_of_key를 이용해 자기 보다 작은 숫자의 개수를 구한다
    // ans를 갱신한다.
    // set에 삽입한 숫자를 관리하기 위해 queue에 현재 넣은 숫자들을 삽입한다
    // Q의 front(현재 S개의 숫자 중 맨 앞에 있는 숫자)를 삭제하기 전,
    // S개의 숫자 중 가장 앞에 있는 숫자보다 큰 숫자들의 개수를 구한다.
    // order_of_key를 이용해 index를 구한 뒤 전체 개수에서 빼서 구할 수 있다.
    // S개의 숫자에서 Q.front()를 삭제한다.
    // 새로 숫자를 삽입한 뒤 order_of_key를 통해 자기보다 작은 숫자의 개수를 구한다
    // Q에도 삽입한다.
    // 이를 계속 반복하며 ans를 갱신하고 답을 출력한다
    ordered_set SET; // ascending
    ordered_set2 SET2; // descending
    queue<i64> Q;
    auto erase2 = [](ordered_set& SET, int val) {
        // for multiset
        int idx = SET.order_of_key(val);
        auto it = SET.find_by_order(idx);
        if (*it == val) SET.erase(it);
    };
    auto erase3 = [](ordered_set2& SET, int val) {
        // for multiset
        int idx = SET.order_of_key(val);
        auto it = SET.find_by_order(idx);
        if (*it == val) SET.erase(it);
    };

    int n, s;
    cin >> n >> s;
    i64 ans = 0;
    i64 sum = 0;
    for (int i = 0; i < s; ++i) {
        i64 x;
        cin >> x;
        Q.push(x);
        SET.insert(x);
        SET2.insert(x);
        sum += SET.order_of_key(x);
    }
    ans = max(ans, sum);
    for (int i = 0; i < n-s; ++i) {
        // 2 4 5 7 8
        // 4 : 1
        // s = 5
        // s-idx
        // Q.front()보다 큰 숫자의 개수
        // SET2.order_of_key(Q.front())
        sum -= SET2.order_of_key(Q.front());
        erase3(SET2, Q.front());
        erase2(SET, Q.front());
        Q.pop();
        i64 x;
        cin >> x;
        Q.push(x);
        SET.insert(x);
        SET2.insert(x);
        sum += SET.order_of_key(x);
        ans = max(ans, sum);
    }
    cout << ans;
}