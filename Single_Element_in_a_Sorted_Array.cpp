#include<bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int>& nums) {
	int n = nums.size(), l = 0, r = n - 1;

	if (n == 1) return nums[0];

	while (l <= r) {
		int mid = (l + ((r - l) >> 2));
		if (nums[mid] == nums[mid ^ 1]) l = mid + 1;
		else r = mid - 1;
	}

	return nums[l];
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		vector<int> nums(n);
		for (int& x : nums) cin >> x;

		cout << singleNonDuplicate(nums) << endl;
	}

	return 0;
}
