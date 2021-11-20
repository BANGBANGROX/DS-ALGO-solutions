#include<bits/stdc++.h>
using namespace std;

int rob(vector<int>& nums) {
	int n = nums.size();
	vector<int> dp(n);

	dp[0] = nums[0];

	for (int i = 1; i < n; ++i) {
		dp[i] = max(dp[i - 1], nums[i]);
		if (i > 1) dp[i] = max(dp[i], dp[i - 2] + nums[i]);
	}

	return dp[n - 1];
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		vector<int> nums(n);
		for (int i = 0; i < n; ++i) cin >> nums[i];

		cout << rob(nums) << endl;
	}
}