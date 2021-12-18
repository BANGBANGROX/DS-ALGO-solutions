#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 1e9 + 7;

int gcd(int a, int b) {
	if (b == 0) return a;

	return gcd(b, a % b);
}

int lcm(int a, int b) {
	return (a * b) / gcd(a, b);
}

bool check(int a, int b, ll val, int n) {
	return (val / a + val / b - val / lcm(a, b)) >= n;
}

int nthMagicalNumber(int n, int a, int b) {
	ll l = 1, r = (ll)n * min(a, b);

	while (l < r) {
		ll mid = (l + ((r - l) >> 2));
		if (check(a, b, mid, n)) r = mid;
		else l = mid + 1;
	}

	return l % mod;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int a, b, n;
		cin >> a >> b >> n;

		cout << nthMagicalNumber(n, a, b) << endl;
	}

	return 0;
}
