#include<bits/stdc++.h>
using namespace std;

class Solution {
	typedef long long ll;

	vector<vector<ll>> dp;
	const int mod = 1e9 + 7;

	ll countOrdersUtil(int unpicked, int undelivered) {
		if (unpicked == 0 && undelivered == 0) return 1;

		if (unpicked < 0 || undelivered < 0 || unpicked > undelivered) return 0;

		if (dp[unpicked][undelivered] != -1) return dp[unpicked][undelivered];

		ll ans = 0;

		// Let's pick the current item
		ans += unpicked * countOrdersUtil(unpicked - 1, undelivered);
		ans %= mod;
	    
		// Let's deliver the current item
		ans += ((ll)undelivered - unpicked) * countOrdersUtil(unpicked, undelivered - 1);
		ans %= mod;

		return dp[unpicked][undelivered] = ans;
	}

public:
	int countOrders(int n) {
		dp = vector<vector<ll>>(n + 1, vector<ll>(n + 1, -1));

		return (int)countOrdersUtil(n, n);
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;

		Solution solution;
		cout << solution.countOrders(n) << endl;
	}

	return 0;
}