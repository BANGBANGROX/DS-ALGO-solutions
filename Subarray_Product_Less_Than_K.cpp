#include<bits/stdc++.h>
using namespace std;

const double error = 1e-9;

int numSubarrayProductLessThanK(vector<int>& nums, int k) {
	if (k == 0) return 0;

	double logk = log10(k);
	int ans = 0;
	vector<double> prefix(nums.size() + 1);

	for (int i = 0; i < nums.size(); ++i) {
		prefix[i + 1] = prefix[i] + log10(nums[i]);
	}

	for (int i = 0; i < prefix.size(); ++i) {
		int l = i + 1, r = prefix.size();
		while (l < r) {
			int mid = (l + ((r - l) >> 2));
			if (prefix[mid] < prefix[i] + logk - error) l = mid + 1;
			else r = mid;
		}
		ans += (l - i - 1);
	}

	return ans;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n, k;
		cin >> n;
		vector<int> nums(n);
		for (int& x : nums) cin >> x;
		cin >> k;

		cout << numSubarrayProductLessThanK(nums, k);
	}

	return 0;
}