#include<bits/stdc++.h>
using namespace std;

int maxProduct(vector<int>& nums) {
	int n = nums.size(), l = 0, r = 0, res = INT_MIN, product = 1;

	while (r < n) {
		while (nums[r] == 0 && l < r) {
			res = max(res, product);
			product /= nums[l];
			++l;
	    }
		if (nums[r] == 0) {
			++l;
			res = max(res, 0);
		}
		else {
			product *= nums[r];
			res = max(res, product);
		}
		++r;
	}

	while (l < r) {
		res = max(res, product);
		product /= nums[l];
		++l;
	}

	return res;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		vector<int> nums(n);
		for (int& x : nums) cin >> x;

		cout << maxProduct(nums) << endl;
	}

	return 0;
}
