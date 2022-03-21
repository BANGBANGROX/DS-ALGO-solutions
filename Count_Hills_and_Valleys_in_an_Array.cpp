// https://leetcode.com/problems/count-hills-and-valleys-in-an-array/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int countHillValley(vector<int>& nums) {
		int n = nums.size();
		int ans = 0;
		int prev = 0;

		for (int i = 1; i < n - 1; ++i) {
			int current = i;
			while (i + 1 < n && nums[i] == nums[i + 1]) {
				++i;
			}
			if (i != n - 1) {
				// Check for hill
				if (nums[current] > nums[prev] && nums[current] > nums[i + 1]) ++ans;
				
				// Check for valley
				if (nums[current] < nums[prev] && nums[current] < nums[i + 1]) ++ans;

				prev = current;
			}
		}

		return ans;
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

		Solution solution;
		cout << solution.countHillValley(nums) << endl;
	}

	return 0;
}