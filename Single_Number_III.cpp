#include<bits/stdc++.h>
using namespace std;

vector<int> singleNumber(vector<int>& nums) {
	int xr = 0;

	for (int x : nums) xr ^= x;

	int rightMostSetBit = xr & (-1 * xr), buck1 = 0, buck2 = 0;

	for (int x : nums) {
		if (rightMostSetBit & x) buck1 ^= x;
		else buck2 ^= x;
	}

	return { buck1,buck2 };
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		vector<int> nums(n);
		for (int i = 0; i < n; ++i) cin >> nums[i];

		vector<int> ans = singleNumber(nums);
		cout << ans[0] << " " << ans[1] << endl;
	}

	return 0;
}