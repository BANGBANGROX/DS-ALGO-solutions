#include<bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
	int n = nums.size(), leftProd = 1;
	vector<int> ans(n);

	ans[n - 1] = 1;

	for (int i = n - 2; i > -1; --i) {
		ans[i] = ans[i + 1] * nums[i + 1];
	}

	for (int i = 0; i < n; ++i) {
		ans[i] *= leftProd;
		leftProd *= nums[i];
	}

	return ans;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		vector<int> nums(n);
		for (int& x : nums) cin >> x;

		vector<int> ans = productExceptSelf(nums);
		for (int x : ans) cout << x << " ";
		cout << endl;
	}

	return 0;
}