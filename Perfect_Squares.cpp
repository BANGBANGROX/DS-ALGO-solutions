#include<bits/stdc++.h>
using namespace std;

const int MAX = 100;

int numSquares(int n) {
	vector<int> coins;
	vector<int> dp(n + 1, INT_MAX);

	for (int i = 1; i <= MAX; ++i) coins.push_back(i * i);

	dp[0] = 0;

	for (int i = 1; i <= n; ++i) {
		for (int coin : coins) {
			if (coin > i) break;
			dp[i] = min(dp[i], dp[i - coin] + 1);
		}
	}

	return dp[n];
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;

		cout << numSquares(n) << endl;
	}

	return 0;
}