#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void partition(ll a[], ll start, ll end, vector<ll>& part) {
	ll n = (end - start + (ll)1);

	for (ll i = 0; i < ((ll)1 << n); ++i) {
		ll sum = 0;
		ll j = start, mask = i;
		while (mask) {
			ll bit = mask & 1;
			if (bit) sum += a[j];
			++j;
			mask >>= 1;
		}
		part.push_back(sum);
	}
}

ll findSubsets(ll a[], ll A, ll B, ll n) {
	vector<ll> v1, v2;
	partition(a, 0, n / 2 - 1, v1);
	partition(a, n / 2, n - 1, v2);
	sort(v2.begin(), v2.end());
	ll ans = 0;

	for (ll x : v1) {
		ll low = lower_bound(v2.begin(), v2.end(), A - x) - v2.begin();
		ll high = upper_bound(v2.begin(), v2.end(), B - x) - v2.begin();
		ans += (high - low);
	}

	return ans;
}

int main() {
	ll n, A, B;
	cin >> n >> A >> B;
	ll* a = new ll[n];
	for (ll i = 0; i < n; ++i) cin >> a[i];

	cout << findSubsets(a, A, B, n) << endl;

	return 0;
}