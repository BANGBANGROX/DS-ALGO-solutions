#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isSufficient(int time, vector<int>& eff, int tot) {
	ll res = 0;

	for (int currEff : eff) {
		ll cnt = (ll)sqrt(currEff * currEff + 8 * currEff * time);
		cnt -= currEff;
		res += cnt / (2 * (ll)currEff);
		if (res >= tot) return true;
	}

	return false;
}

ll findMinTime(vector<int>& eff, int tot) {
	ll low = 0, high = 10 * tot * (tot + 1) / 2;

	while (low < high) {
		ll mid = (low + high) / 2;
		if (isSufficient(mid, eff, tot)) {
			high = mid;
		}
		else {
			low = mid + (ll)1;
		}
	}

	return low;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int tot, n;
		cin >> tot >> n;
		vector<int> eff(n);
		for (int i = 0; i < n; ++i) cin >> eff[i];

		cout << findMinTime(eff, tot) << endl;
	}

	return 0;
}