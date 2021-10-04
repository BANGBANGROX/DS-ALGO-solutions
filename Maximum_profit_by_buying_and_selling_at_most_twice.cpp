#include<bits/stdc++.h>
using namespace std;

int findMaxProfit(int prices[], int n) {
	vector<int> profit(n);
	int maxPrice = prices[n - 1];
	int minPrice = prices[0];

	for (int i = n - 2; i > -1; --i) {
		if (prices[i] > maxPrice) {
			maxPrice = prices[i];
		}
		profit[i] = max(profit[i + 1], maxPrice - prices[i]);
	}
	for (int i = 1; i < n; ++i) {
		if (prices[i] < minPrice) {
			minPrice = prices[i];
		}
		profit[i] = max(profit[i - 1], profit[i] + prices[i] - minPrice);
	}
    
	return profit[n - 1];
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		int* a = new int[n];
		for (int i = 0; i < n; ++i) cin >> a[i];

		cout << findMaxProfit(a, n) << endl;
	}

	return 0;
}
