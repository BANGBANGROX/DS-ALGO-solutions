#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool checkPossibility(vector<int>& nums) {
		int n = nums.size();
		bool modified = false;

		for (int i = 1; i < n; ++i) {
			if (nums[i] >= nums[i - 1]) continue;
			if (modified) return false;
			if (i > 1 && nums[i - 2] > nums[i]) nums[i] = nums[i - 1];
			else nums[i - 1] = nums[i];
			modified = true;
		}

		return true;
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
		if (solution.checkPossibility(nums)) cout << "true\n";
		else cout << "false\n";
	}

	return 0;
}