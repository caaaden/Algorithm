#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n;
	cin >> n;
	// f(n) % 1,000,000
	// f(0) = 0
	// f(1) = 1
	// f(2) = 1
	// f(3) = 2
	// …
	long long a = 0;
	long long b = 1;
	n %= 1500000;
	for (long long i = 0; i < n-1; ++i) {
		long long tmp = a + b;
		a = b % 1000000;
		b = tmp % 1000000;
	}
	cout << b;
}