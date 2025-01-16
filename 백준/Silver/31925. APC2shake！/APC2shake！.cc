#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

#define fastio ios::sync_with_stdio(0), cin.tie(0);
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define X first
#define Y second
#define rep(i, a, b) for (int i = a; i < b; ++i)

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using psi = pair<string, int>;
using piii = pair<int, pii>;
using piiii = pair<pii, pii>;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

constexpr int dx[4] = {1, -1, 0, 0};
constexpr int dy[4] = {0, 0, 1, -1};
constexpr int bit = 9;
constexpr int MOD = 1e9;

int main()
{
    fastio;
    
    int n;
    cin >> n;
    vector<psi> competitors;
    for (int i = 0; i < n; ++i) {
        string name, enrolled, won;
        int shakeRank, apcRank;
        cin >> name >> enrolled >> won >> shakeRank >> apcRank;
        if (enrolled == "hewhak") continue;
        if (won == "winner") continue;
        if (shakeRank >= 1 && shakeRank <= 3) continue;
        competitors.push_back({name, apcRank});
    }
    sort(all(competitors), [](const psi& a, const psi& b) {
        return a.Y < b.Y;
    });
    vector<string> qualifiers;
    for (int i = 0; i < min((int)competitors.size(), 10); ++i) {
        qualifiers.push_back(competitors[i].X);
    }
    sort(all(qualifiers));
    cout << qualifiers.size() << '\n';
    for (auto& name : qualifiers) cout << name << '\n';
}