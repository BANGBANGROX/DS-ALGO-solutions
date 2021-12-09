#include<bits/stdc++.h>
using namespace std;

bool check(vector<int>& nums, int len, int target) {
	int n = nums.size(), l = 0, r = len - 1, sum = 0;

	for (int i = l; i <= r; ++i) {
		sum += nums[i];
	}

	while (r < n) {
		if (sum >= target) return true;
		sum -= nums[l];
		++l;
		++r;
		if (r < n) sum += nums[r];
	}

	return false;
}

int minSubArrayLen(int target, vector<int>& nums) {
	int n = nums.size(), l = 1, r = n, ans = 0;

	while (l <= r) {
		int mid = (l + ((r - l) >> 2));
		if (check(nums, mid, target)) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}

	return ans;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n, target;
		cin >> n;
		vector<int>nums(n);
		for (int& x : nums) cin >> x;
		cin >> target;

		cout << minSubArrayLen(target, nums) << endl;
	}

	return 0;
}
