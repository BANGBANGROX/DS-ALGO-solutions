#include<bits/stdc++.h>
using namespace std;

int maxProfit(int n, int k, vector<int>& a) {
	vector<vector<int>> profit(k + 1, vector<int>(n)); // profit[i][j] is the profit for i transactions till ith day
	// originally profit[i][j] = max(profit[i][j-1], max(a[i]-a[k]+profit[i-1][k] for k [0...j-1])) but we stored 
	// max(profit[i-1][k]-a[k]) for every day k in prevDiff as prevDiff = max(profit[i-1][j-1] - a[j-1])

	for (int i = 1; i <= k; ++i) {
		int prevDiff = INT_MIN;
		for (int j = 1; j < n; ++j) {
			prevDiff = max(prevDiff, profit[i - 1][j - 1] - a[j - 1]);
			profit[i][j] = max(profit[i][j - 1], prevDiff + a[j]);
		}
	}

	return profit[k][n - 1];
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		for (int& x : a) cin >> x;
		cout << maxProfit(n, k, a) << endl;
	}

	return 0;
}
