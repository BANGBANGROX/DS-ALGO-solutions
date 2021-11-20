#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
	int n = prices.size(), ans = 0;

	for (int i = 1; i < n; ++i) {
		if (prices[i] > prices[i - 1]) ans += (prices[i] - prices[i - 1]);
	}

	return ans;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		vector<int> prices(n);
		for (int& x : prices) cin >> x;

		cout << maxProfit(prices) << endl;
	}

	return 0;
}