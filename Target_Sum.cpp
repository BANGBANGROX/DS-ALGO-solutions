#include<bits/stdc++.h>
using namespace std;

class Solution {
	int total = 0;
	vector<vector<int>> dp;

	int findTargetSumWaysUtil(vector<int>& nums, int currentSum, int index, int target) {
		if (index == nums.size()) {
			if (currentSum == target) return 1;
			return 0;
		}

		if (dp[index][currentSum + total] != -1) return dp[index][currentSum + total];

		// Let's take the '+' sign i.e. newSum = currentSum + nums[index]
		int add = findTargetSumWaysUtil(nums, currentSum + nums[index], index + 1, target);

		// Now we take '-' sign i.e newSum = currentSum - nums[index]
		int subtract = findTargetSumWaysUtil(nums, currentSum - nums[index], index + 1, target);

		return dp[index][currentSum + total] = add + subtract;
	}

public:
	int findTargetSumWays(vector<int>& nums, int target) {
		total = 0;
		int n = nums.size();

		for (int num : nums) {
			total += num;
		}

		dp = vector<vector<int>>(n, vector<int>(2 * total + 1, -1));

		return findTargetSumWaysUtil(nums, 0, 0, target);
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n, target;
		cin >> n;
		vector<int> nums(n);
		for (int i = 0; i < n; ++i) {
			cin >> nums[i];
		}
		cin >> target;

		Solution solution;
		cout << solution.findTargetSumWays(nums, target) << endl;
	}

	return 0;
}