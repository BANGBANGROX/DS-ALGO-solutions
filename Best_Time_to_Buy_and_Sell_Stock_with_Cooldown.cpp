#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
	int n = prices.size(), buy = -1 * prices[0], sell = 0, cool = 0;

	for (int i = 1; i < n; ++i) {
		int temp = sell;
		if (buy + prices[i] > sell) sell = buy + prices[i];
		if (cool - prices[i] > buy) buy = cool - prices[i];
		cool = sell;
	}

	return max(buy, sell);
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
