#include <bits/stdc++.h>
using namespace std;
#define size 100005
int w[size]; /* node weights */
int l[size], r[size]; /* left and right children */
int d[size]; /* depth */
int q[size]; /* working region */
int v[size]; /* number of node in working region */
int t; /* current size of working region */
int m; /* current node */

/*Phase 1 : Function builds a rooted binary tree having the values
 as leaves but possibly in the wrong order*/
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

/*Phase 2 : Function finds the depth of the each node and
stores it in the depth array */
void mark(int k, int p) {
	d[k] = p;
	if (l[k] >= 0)
		mark(l[k], p + 1);
	if (r[k] >= 0)
		mark(r[k], p + 1);
}

/*Phase 3: Function reorders the leaf nodes
in the same order as of the original sequence given*/
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
        q[0] = 1000000000; /* infinity */
        q[1] = w[0];
        v[1] = 0;
        for (int i = 1; i <= n; i++) {
            while (q[t - 1] <= w[i])
                combine(t);
            t++;
            q[t] = w[i];
            v[t] = i;
        }
        while (t > 1)
            combine(t);
        mark(v[1], 0);
        t = 0;
        m = 2 * n;
        build(1);
        for (int i = 0 ; i <= 2 * n; i++) {
            int ans = 0;
            if (l[i] != -1) ans += w[l[i]];
            else ans = w[i];
            if (r[i] != -1) ans += w[r[i]];
            else ans = w[i];
            w[i] = ans;
        }
        for (int i = 2 * n ; i >= 0 ; i--) {
            if (r[i] != -1) {
                d[r[i]] = d[i] + 1;
            }
            if (l[i] != -1) {
                d[l[i]] = d[i] + 1;
            }
        }
        int sum = 0;
        for (int i = n+1; i <= 2*n; ++i) sum += w[i];
        cout << sum << '\n';
    }
}