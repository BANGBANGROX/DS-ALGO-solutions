#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll minCost(ll a[], ll n) {
	ll res = 0;
	priority_queue<ll, vector<ll>, greater<ll>> q;

	for (int i = 0; i < n; ++i) {
		q.push(a[i]);
	}

	while (q.size() > 1) {
		ll val1 = q.top();
		q.pop();
		ll val2 = q.top();
		q.pop();
		res += (val1 + val2);
		q.push(val1 + val2);
	}

	return res;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		ll n;
		cin >> n;
		ll* a = new ll[n];
		for (int i = 0; i < n; ++i) cin >> a[i];

		cout << minCost(a, n) << endl;
	}

	return 0;
}