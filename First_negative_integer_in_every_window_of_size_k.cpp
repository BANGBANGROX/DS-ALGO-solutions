#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<ll> printFirstNegativeInteger(ll A[], ll n, ll k) {
	queue<ll> q;
	vector<ll> res;

	for (ll i = 0; i < k; ++i) {
		if (A[i] < 0) q.push(i);
	}

	for (ll i = k; i < n; ++i) {
		if (q.empty()) res.push_back(0);
		else res.push_back(A[q.front()]);
		while (!q.empty() && q.front() <= i - k) q.pop();
		if (A[i] < 0) q.push(i);
	}
	if (q.empty()) res.push_back(0);
	else res.push_back(A[q.front()]);

	return res;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		ll n, k;
		cin >> n >> k;
		ll* a = new ll[n];
		for (int i = 0; i < n; ++i) cin >> a[i];

		vector<ll> res = printFirstNegativeInteger(a, n, k);
		for (ll x : res) cout << x << " ";
		cout << endl;
	}
}
