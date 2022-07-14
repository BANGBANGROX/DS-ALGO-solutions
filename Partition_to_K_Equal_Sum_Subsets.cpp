#include<bits/stdc++.h>
using namespace std;

class Solution {
	bool canPartitionKSubsets(vector<int>& nums, int index, int k, 
		int subsetSum, int currentSum, vector<bool>& visited) {
		if (k == 1) return true;

		if (currentSum == subsetSum) {
			return canPartitionKSubsets(nums, 0, k - 1, subsetSum, 0, visited);
		}

		int n = nums.size();

		for (int i = index; i < n; ++i) {
			if (visited[i] || currentSum + nums[i] > subsetSum) continue;
			currentSum += nums[i];
			visited[i] = true;
			if (canPartitionKSubsets(nums, i + 1, k, subsetSum, currentSum, visited)) return true;
			currentSum -= nums[i];
			visited[i] = false;
		}

		return false;
	}

public:
	bool canPartitionKSubsets(vector<int>& nums, int k) {
		int n = nums.size();
		int totalSum = accumulate(nums.begin(), nums.end(), 0);

		if (totalSum % k != 0) return false;

		int subsetSum = totalSum / k;
		int index = 0;
		int currentSum = nums[index];
		vector<bool> visited(n);

		visited[index] = true;

		return canPartitionKSubsets(nums, index, k, subsetSum, currentSum, visited);
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		vector<int> nums(n);
		for (int& x : nums) cin >> x;
		int k;
		cin >> k;

		Solution solution;
		cout << solution.canPartitionKSubsets(nums, k) << endl;
	}

	return 0;
}