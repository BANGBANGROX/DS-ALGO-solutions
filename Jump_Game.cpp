#include<bits/stdc++.h>
using namespace std;

bool canJump(vector<int>& nums) {
	int n = nums.size(), steps = nums[0], maxReach = nums[0];

	if (steps == 0) return false;

	for (int i = 1; i < n; ++i) {
		if (i == n - 1) return true;
		maxReach = max(maxReach, i + nums[i]);
		--steps;
		if (steps == 0) {
			if (i >= maxReach) return false;
			steps = maxReach - i;
		}
	}

	return false;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		vector<int> nums(n);
		for (int& x : nums) cin >> x;

		if (canJump(nums)) cout << "Possible\n";
		else cout << "Not Possible\n";
	}

	return 0;
}
