#include<bits/stdc++.h>
using namespace std;

vector<int> candyStore(int candies[], int n, int k) {
	int lastMarked = n, firstMarked = -1, minCost = 0, maxCost = 0;

	sort(candies, candies + n);

	for (int i = 0; i < n; ++i) {
		if (i >= lastMarked) break;
		minCost += candies[i];
		lastMarked -= k;
	}
	for (int i = n - 1; i > -1; --i) {
		if (i <= firstMarked) break;
		maxCost += candies[i];
		firstMarked += k;
	}

	return { minCost,maxCost };
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, k;
		cin >> n >> k;
		int* a = new int[n];
		for (int i = 0; i < n; ++i) cin >> a[i];

		vector<int> ans = candyStore(a, n, k);
		cout << ans[0] << " " << ans[1] << endl;
	}

	return 0;
}