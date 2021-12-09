#include<bits/stdc++.h>
using namespace std;

int findMinUtil(vector<int>& nums, int l, int r) {
	if (l > r) return -1;

	if (l == r) return nums[l];

	if (nums[r] > nums[0]) return nums[0];

	int mid = (l + ((r - l) >> 2)), n = nums.size();

	if (mid + 1 < n && nums[mid + 1] < nums[mid]) return nums[mid + 1];

	if (mid > 0 && nums[mid - 1] > nums[mid]) return nums[mid];

	if (nums[0] > nums[mid]) return findMinUtil(nums, l, mid - 1);

	return findMinUtil(nums, mid + 1, r);
}

int findMin(vector<int>& nums) {
	int n = nums.size();

	return findMinUtil(nums, 0, n - 1);
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		vector<int> nums(n);
		for (int& x : nums) cin >> x;

		cout << findMin(nums) << endl;
	}

	return 0;
}