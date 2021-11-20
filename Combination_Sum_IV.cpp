#include<bits/stdc++.h>
using namespace std;

int combinationSum4(vector<int>& nums, int target) {
	int n = nums.size();
	vector<unsigned int> dp(target + 1);

	dp[0] = 1;

	for (int amt = 1; amt <= target; ++amt) {
		for (int i = 0; i < n; ++i) {
			if (nums[i] <= amt) dp[amt] += dp[amt - nums[i]];
		}
	}

	return dp[target];
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n, target;
		cin >> n;
		vector<int> nums(n);
		for (int& x : nums) cin >> x;
		cin >> target;

		cout << combinationSum4(nums, target) << endl;
	}

	return 0;
}