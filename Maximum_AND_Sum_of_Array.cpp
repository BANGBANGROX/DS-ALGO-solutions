#include<bits/stdc++.h>
using namespace std;

class Solution {
	int setBitCount(int num) {
		int ans = 0;

		while (num > 0) {
			if ((num & 1) > 0) ++ans;
			num /= 2;
		}

		return ans;
	}

public:
	int maximumANDSum(vector<int>& nums, int numSlots) {
		int n = 2 * numSlots;
		vector<int> dp(1 << n);

		while (nums.size() < n) nums.push_back(0);

		for (int mask = 1; mask < (1 << n); ++mask) {
			int slotNumber = (setBitCount(mask) + 1) / 2;
			for (int i = 0; i < n; ++i) {
				if ((mask & (1 << i)) > 0) {
					dp[mask] = max(dp[mask], dp[mask ^ (1 << i)] + (nums[i] & slotNumber));
				}
			}
		}

		return dp[(1 << n) - 1];
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n, numSlots;
		cin >> n;
		vector<int> nums(n);
		for (int& x : nums) cin >> x;
		cin >> numSlots;

		Solution solution;
		cout << solution.maximumANDSum(nums, numSlots) << endl;
	}

	return 0;
}