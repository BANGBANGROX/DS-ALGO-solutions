#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll maximizeSum(ll a[], int n, int k) {
	ll res = 0, leastAbs = 1e9 + 5;
	int cnt = 0;

	sort(a, a + n);

	for (int i = 0; i < n; ++i) {
		leastAbs = min(leastAbs, abs(a[i]));
		if (a[i] < 0) {
			if (cnt < k) {
				++cnt;
				res += abs(a[i]);
			}
			else res += a[i];
		}
		else res += a[i];
	}
	k -= cnt;
	k %= 2;

	if (k == 0) return res;

	res -= 2 * leastAbs;

	return res;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, k;
		cin >> n >> k;
		ll* a = new ll[n];
		for (int i = 0; i < n; ++i) cin >> a[i];

		cout << maximizeSum(a, n, k) << endl;
	}

	return 0;
}