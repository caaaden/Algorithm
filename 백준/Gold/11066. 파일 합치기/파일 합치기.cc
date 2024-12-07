#include <bits/stdc++.h>
using namespace std;
#define size 100005
int w[size];
int l[size], r[size];
int d[size];
int q[size];
int v[size];
int t;
int m;

void combine(int k) {
	int j, d, x;
	m++;
	l[m] = v[k - 1];
	r[m] = v[k];
	w[m] = x = q[k - 1] + q[k];
	t--;
	for (j = k; j <= t; j++)
		q[j] = q[j + 1], v[j] = v[j + 1];
	for (j = k - 2; q[j] < x; j--)
		q[j + 1] = q[j], v[j + 1] = v[j];
	q[j + 1] = x;
	v[j + 1] = m;
	while (j > 0 && q[j - 1] <= x) {
		d = t - j;
		combine(j);
		j = t - d;
	}
}

void mark(int k, int p) {
	d[k] = p;
	if (l[k] >= 0)
		mark(l[k], p + 1);
	if (r[k] >= 0)
		mark(r[k], p + 1);
}

void build(int b) {
	int j = m;
	if (d[t] == b)	l[j] = t++;
	else {
		m--;
		l[j] = m;
		build(b + 1);
	}
	if (d[t] == b)	r[j] = t++;
	else {
		m--;
		r[j] = m;
		build(b + 1);
	}
}

int main() {

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
        q[0] = 1e9; /* infinity */
        q[1] = w[0];
        v[1] = 0;
        for (int i = 1; i <= n; i++) {
            while (q[t - 1] <= w[i])
                combine(t);
            t++;
            q[t] = w[i];
            v[t] = i;
        }
        while (t > 1) combine(t);
        mark(v[1], 0);
        t = 0;
        m = n*2;
        build(1);
        for (int i = 0; i <= n*2; i++) {
//            int ans = 0;
//            if (l[i] != -1) ans += w[l[i]];
//            else ans = w[i];
//            if (r[i] != -1) ans += w[r[i]];
//            else ans = w[i];
//            w[i] = ans;

            // 두 자식 모두 존재할 떄 w[i] = w[l[i]] + w[r[i]]
            //
            if (l[i] != -1 && r[i] != -1) w[i] = w[l[i]] + w[r[i]];
        }
//        for (int i = n*2; i >= 0; i--) {
//            if (r[i] != -1) d[r[i]] = d[i] + 1;
//            if (l[i] != -1) d[l[i]] = d[i] + 1;
//        }
        int sum = 0;
        for (int i = n+1; i <= 2*n; ++i) sum += w[i];
        cout << sum << '\n';
    }
}