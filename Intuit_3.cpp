#include<bits/stdc++.h>
using namespace std;

int solve(int n, int nums[]) {
	int sum = 0;

	for (int i = 0; i < n; ++i) sum += nums[i];

	vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1));

	for (int i = 0; i <= n; ++i) dp[i][0] = true;

	for (int i = 1; i <= n; ++i) {
		for (int currSum = 1; currSum <= sum; ++currSum) {
			dp[i][currSum] = dp[i - 1][currSum];
			if (currSum >= nums[i - 1]) dp[i][currSum] = dp[i][currSum] | dp[i - 1][currSum - nums[i - 1]];
		}
	}

	for (int i = sum / 2; i <= sum; ++i) {
		if (dp[n][i]) {
			return sum - 2 * i;
		}
	}

	return -1;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		int* nums = new int[n];
		for (int i = 0; i < n; ++i) cin >> nums[i];

		cout << solve(n, nums) << endl;
	}

	return 0;
}
