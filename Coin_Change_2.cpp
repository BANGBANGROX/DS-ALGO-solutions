#include<bits/stdc++.h>
using namespace std;

int change(int amount, vector<int>& coins) {
	int n = coins.size();
	vector<vector<int>> dp(n + 1, vector<int>(amount + 1));

	dp[0][0] = 1;

	for (int i = 1; i <= n; ++i) {
		dp[i][0] = 1;
		for (int amt = 1; amt <= amount; ++amt) {
			dp[i][amt] += dp[i - 1][amt];
			if (coins[i - 1] <= amt) dp[i][amt] += dp[i][amt - coins[i - 1]];
		}
	}

	return dp[n][amount];
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n, amount;
		cin >> n >> amount;
		vector<int> coins(n);
		for (int& x : coins) cin >> x;

		cout << change(amount, coins) << endl;
	}

	return 0;
}
