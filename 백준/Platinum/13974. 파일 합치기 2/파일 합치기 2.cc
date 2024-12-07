#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
#define size 45555
ll w[size];
int l[size], r[size];
int d[size];
ll q[size];
int v[size];
int t;
int m;

void combine(int k) {
	int i, tmp, x;
	m++;
	l[m] = v[k - 1];
	r[m] = v[k];
	w[m] = x = q[k - 1] + q[k];
	t--;
	for (i = k; i <= t; i++) q[i] = q[i + 1], v[i] = v[i + 1];
	for (i = k - 2; q[i] < x; i--) q[i + 1] = q[i], v[i + 1] = v[i];
	q[i + 1] = x;
	v[i + 1] = m;
	while (i > 0 && q[i - 1] <= x) {
        tmp = t - i;
		combine(i);
        i = t - tmp;
	}
}

void mark(int k, int p) {
	d[k] = p;
	if (l[k] >= 0) mark(l[k], p + 1);
	if (r[k] >= 0) mark(r[k], p + 1);
}

void build(int b) {
	int j = m;
	if (d[t] == b) l[j] = t++;
	else {
		m--;
		l[j] = m;
		build(b+1);
	}
	if (d[t] == b) r[j] = t++;
	else {
		m--;
		r[j] = m;
		build(b+1);
	}
}

int main() {
    fastio;

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n; n--;
        for (int i = 0; i <= n; i++) {
            cin >> w[i];
            l[i] = r[i] = -1;
        }
        m = n;
        t = 1;
        q[0] = 1e9;
        q[1] = w[0];
        v[1] = 0;
        for (int i = 1; i <= n; i++) {
            while (q[t - 1] <= w[i]) combine(t);
            t++;
            q[t] = w[i];
            v[t] = i;
        }
        while (t > 1) combine(t);
        mark(v[1], 0);
        t = 0;
        m = n*2;
        build(1);
        for (int i = 0; i <= n*2; i++) if (l[i] != -1 && r[i] != -1) w[i] = w[l[i]] + w[r[i]];
        ll sum = 0;
        for (int i = n+1; i <= 2*n; ++i) sum += w[i];
        cout << sum << '\n';
    }
}