#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll findMinDiff(vector<ll> a, ll n, ll m) {
	ll minDiff = LONG_MAX;

	sort(a.begin(), a.end());

	for (ll i = 0; i + m - 1 < n; ++i) {
		minDiff = min(minDiff, a[i + m - 1] - a[i]);
	}

	return minDiff;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		ll n, m;
		cin >> n >> m;
		vector<ll> a(n);
		for (ll& x : a) cin >> x;

		cout << findMinDiff(a, n, m) << endl;
	}

	return 0;
}
