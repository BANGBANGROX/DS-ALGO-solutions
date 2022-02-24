#include<bits/stdc++.h>
using namespace std;

class Solution {
	typedef long long ll;
public:
	vector<ll> maximumEvenSplit(ll finalSum) {
		if ((finalSum & 1) > 0) return {};

		ll maxSize = sqrt(finalSum);
		ll num = 2;
		vector<ll> ans;

		for (ll i = 1; i < maxSize; ++i) {
			ans.push_back(num);
			num += 2;
		}

		while (true) {
			if (ans.empty()) {
				ans.push_back(finalSum);
				return ans;
			}
			ll k = ans.size();
			ll sum = k * (k + 1);
			ll remainingValue = finalSum - sum;
			if (remainingValue > ans.back()) {
				ans.push_back(remainingValue);
				return ans;
			}
			else ans.pop_back();
		}

		return ans;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		long long finalSum;
		cin >> finalSum;

		Solution solution;
		vector<long long> ans = solution.maximumEvenSplit(finalSum);
		for (long long& x : ans) cout << x << " ";
		cout << endl;
	}

	return 0;
}