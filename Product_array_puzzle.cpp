#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<ll> productExceptSelf(vector<ll>& a, int n) {
	ll totalProd = 1;
	int zeroes = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] != 0) totalProd *= a[i];
		else ++zeroes;
	}

	for (int i = 0; i < n; ++i) {
		if (zeroes > 0) {
			if (zeroes > 1) a[i] = 0;
			else if (a[i] == 0) a[i] = totalProd;
			else a[i] = 0;
		}
		else a[i] = totalProd / a[i];
	}

	return a;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<ll> a(n);
		for (ll& x : a) cin >> x;

		vector<ll> ans = productExceptSelf(a, n);
		for (ll x : ans) cout << x << " ";
		cout << endl;
	}

	return 0;
}