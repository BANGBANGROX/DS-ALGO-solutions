#include<bits/stdc++.h>
using namespace std;

int minCostClimbingStairs(vector<int>& cost) {
	int n = cost.size();
	vector<int> dp(n);

	for (int i = n - 1; i > -1; --i) {
		dp[i] = cost[i];
		if (i < n - 2) dp[i] += min(dp[i + 1], dp[i + 2]);
	}

	return n > 1 ? min(dp[0], dp[1]) : dp[0];
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		vector<int> cost(n);
		for (int& x : cost) cin >> x;

		cout << minCostClimbingStairs(cost) << endl;
	}

	return 0;
}
