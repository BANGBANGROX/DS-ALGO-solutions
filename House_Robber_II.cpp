#include<bits/stdc++.h>
using namespace std;

int robUtil(vector<int>& nums, int l, int r) {
	vector<int> dp(r);

	dp[l] = nums[l];

	for (int i = l + 1; i < r; ++i) {
		dp[i] = max(dp[i - 1], nums[i]);
		if (i > 1) dp[i] = max(dp[i], dp[i - 2] + nums[i]);
	}

	return dp[r - 1];
}

int rob(vector<int>& nums) {
	int n = nums.size();

	if (n == 1) return nums[0];
	if (n == 2) return max(nums[0], nums[1]);

	int inclFirst = robUtil(nums, 0, n - 1);
	int inclLast = robUtil(nums, 1, n);

	return max(inclFirst, inclLast);
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		vector<int> nums(n);
		for (int& x : nums) cin >> x;

		cout << rob(nums) << endl;
	}

	return 0;
}