#include<bits/stdc++.h>
using namespace std;

int maxSubarraySum(vector<int>& nums) {
	int res = nums[0], n = nums.size();

	for (int i = 1; i < n; ++i) {
		if (nums[i - 1] > 0) nums[i] += nums[i - 1];
		res = max(res, nums[i]);
	}

	return res;
}

int minSubarraySum(vector<int>& nums) {
	int res = nums[0], n = nums.size();

	for (int i = 1; i < n; ++i) {
		if (nums[i - 1] < 0) nums[i] += nums[i - 1];
		res = min(res, nums[i]);
	}

	return res;
}

int maxSubarraySumCircular(vector<int>& nums) {
	int sum = 0;
	vector<int> temp1 = nums, temp2 = nums;

	for (int num : nums) sum += num;

	int maxSum = maxSubarraySum(temp1);
	int minSum = minSubarraySum(temp2);

	if (maxSum < 0 && minSum < 0 && sum < 0) return min(maxSum, sum - minSum);

	return max(maxSum, sum - minSum);
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		vector<int> nums(n);
		for (int& x : nums) cin >> x;

		cout << maxSubarraySumCircular(nums) << endl;
	}

	return 0;
}
