#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		int n = nums.size();
		int l = 0;
		int r = n - 1;
		vector<pair<int, int>> numsAndIndexes(n);

		for (int i = 0; i < n; ++i) {
			numsAndIndexes[i] = { nums[i], i };
		}

		sort(numsAndIndexes.begin(), numsAndIndexes.end());

		while (l < r) {
			int a = numsAndIndexes[l].first;
			int b = numsAndIndexes[r].first;
			int sum = a + b;
			if (sum == target) return { numsAndIndexes[l].second, numsAndIndexes[r].second };
			else if (sum > target) --r;
			else ++l;
		}

		return {};
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
		int target;
		cin >> target;

		Solution solution;
		vector<int> ans = solution.twoSum(nums, target);
		cout << ans[0] << " " << ans[1] << endl;
	}

	return 0;
}