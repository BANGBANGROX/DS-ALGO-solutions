#include<bits/stdc++.h>
using namespace std;

int wiggleMaxLength(vector<int>& nums) {
	int n = nums.size();

	if (n < 2) return n;

	int prevDiff = nums[1] - nums[0];
	int length = (prevDiff == 0) ? 1 : 2;

	for (int i = 2; i < n; ++i) {
		int diff = nums[i] - nums[i - 1];
		if (prevDiff >= 0 && diff < 0 || prevDiff <= 0 && diff > 0) {
			++length;
			prevDiff = diff;
		}
	}

	return length;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		vector<int> nums(n);
		for (int& x : nums) cin >> x;

		cout << wiggleMaxLength(nums) << endl;
	}

	return 0;
}
