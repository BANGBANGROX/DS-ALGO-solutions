#include<bits/stdc++.h>
using namespace std;

int jump(vector<int>& nums) {
	int n = nums.size(), steps = nums[0], jumps = 1, maxReach = nums[0];

	if (n == 1) return 0;

	for (int i = 1; i < n; ++i) {
		if (i == n - 1) return jumps;
		maxReach = max(maxReach, nums[i] + i);
		--steps;
		if (steps == 0) {
			++jumps;
			steps = maxReach - i;
		}
	}

	return -1;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		vector<int> nums(n);
		for (int& x : nums) cin >> x;

		cout << jump(nums) << endl;
	}

	return 0;
}