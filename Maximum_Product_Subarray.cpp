#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll maxProduct(vector<int>& a, int n) {
	ll maxEnding = 1, minEnding = 1, maxOverall = 0;
	bool flag = 0, isZero = 0;

	for (int i = 0; i < n; ++i) {
		if (a[i] > 0) {
			maxEnding = maxEnding * (ll)a[i];
			minEnding = min(minEnding * (ll)a[i], (ll)1);
			flag = 1;
		}
		else if (a[i] == 0) {
			maxEnding = 1;
			minEnding = 1;
			isZero = 1;
		}
		else {
			ll temp = maxEnding;
			maxEnding = max((ll)1, minEnding * (ll)a[i]);
			minEnding = temp * a[i];
		}
		maxOverall = max(maxOverall, maxEnding);
	}
	if (!flag && isZero && maxOverall == 1) maxOverall = 0;

	return maxOverall;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int& x : a) cin >> x;

		cout << maxProduct(a, n) << endl;
	}

	return 0;
}