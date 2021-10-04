#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll findMinWork(ll n, ll a[]) {
	vector<pair<ll, ll>> buyer, seller;
	ll totalWork = 0, i = 0, j = 0;

	for (int i = 0; i < n; ++i) {
		if (a[i] >= 0) buyer.push_back({ a[i],i });
		else seller.push_back({ a[i],i });
	}

	while (i < buyer.size() and j < seller.size()) {
		ll minVal = min(buyer[i].first, -1 * seller[j].first);
		buyer[i].first -= minVal;
		seller[j].first += minVal;
		ll dist = abs(buyer[i].second - seller[j].second);
		totalWork += (dist * minVal);
		if (buyer[i].first == 0)  ++i;
		if (seller[j].first == 0) ++j;
	}

	return totalWork;
}

int main() {
	ll n;
	cin >> n;
	while (true) {
		ll* a = new ll[n];
		for (int i = 0; i < n; ++i) cin >> a[i];

		cout << findMinWork(n, a) << endl;

		cin >> n;
		if (n == 0) break;
	}

	return 0;
}