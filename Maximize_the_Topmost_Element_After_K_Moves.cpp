// https://leetcode.com/problems/maximize-the-topmost-element-after-k-moves/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int maximumTop(vector<int>& nums, int k) {
		int n = nums.size();

		if (n == 1 && (k & 1) > 0) return -1;

		if (k == 1) return nums[1];

		int maxElement = nums[0];

		for (int i = 1; i < min(k - 1, n); ++i) {
			maxElement = max(maxElement, nums[i]);
		}

		if (k < n) maxElement = max(maxElement, nums[k]);

		return maxElement;
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
		cout << solution.maximumTop(nums, k) << endl;
	}

	return 0;
}