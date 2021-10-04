#include<bits/stdc++.h>
using namespace std;
typedef long double ld;

int factorial(int n) {
	if (n == 0 || n == 1) return 1;
	return n * factorial(n - 1);
}

ld sinx(int n, ld x) {
	if (n == 1) return x;
	int power = 2 * n - 1;
	return pow(-1, n + 1) * pow(x, power) / (ld)factorial(power) + sinx(n - 1, x);
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		ld x;
		cin >> n >> x;
		cout << sinx(n, x) << endl;
	}

	return 0;
}


