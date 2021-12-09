#include<bits/stdc++.h>
using namespace std;

int maxProduct(vector<int>& nums) {
	int maxProduct = nums[0], maxi = nums[0], mini = nums[0], n = nums.size();

	for (int i = 1; i < n; ++i) {
		if (nums[i] < 0) swap(maxi, mini);
		maxi = max(nums[i], nums[i] * maxi);
		mini = min(nums[i], nums[i] * mini);
		maxProduct = max(maxi, maxProduct);
	}

	return maxProduct;
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
