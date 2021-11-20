#include<bits/stdc++.h>
using namespace std;

int integerBreak(int n) {
	vector<int> dp(n + 1);

	if (n == 2) return 1;

	if (n == 3) return 2;

	dp[0] = 1;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= i; ++j) {
			dp[i] = max(dp[i], j * dp[i - j]);
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

		cout << integerBreak(n) << endl;
	}
}
