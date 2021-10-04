#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll countTriplets(ll a[], int n, ll sum) {
	ll cnt = 0;
	sort(a, a + n);

	for (int i = 0; i < n - 1; ++i) {
		int l = i + 1, r = n - 1;
		ll target = sum - a[i];
		while (l < r) {
			ll currSum = a[l] + a[r];
			if (currSum < target) {
				cnt += ((ll)r - l);
				++l;
			}
			else --r;
		}
	}

	return cnt;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		ll sum;
		cin >> n >> sum;
		ll* a = new ll[n];
		for (int i = 0; i < n; ++i) cin >> a[i];

		cout << countTriplets(a, n, sum) << endl;
	}

	return 0;
}