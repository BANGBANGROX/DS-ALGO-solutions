#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll findSubarray(vector<ll> a, int n, ll k = 0) {
	map<ll, ll> m;
	ll currSum = 0, res = 0;

	for (int i = 0; i < n; ++i) {
		currSum += a[i];
		if (currSum == k) ++res;
		if (m.find(currSum - k) != m.end()) res += m[currSum];
		m[currSum]++;
	}

	return res;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<ll> a(n);
		for (ll& x : a) cin >> x;

		cout << findSubarray(a, n) << endl;
	}

	return 0;
}