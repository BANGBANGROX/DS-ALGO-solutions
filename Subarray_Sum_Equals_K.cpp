#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
	int n = nums.size(), ans = 0, sum = 0;
	unordered_map<int, int> mp;

	for (int i = 0; i < n; ++i) {
		++mp[sum];
		sum += nums[i];
		ans += mp[sum - k];
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

		cout << subarraySum(nums, k) << endl;
	}

	return 0;
}
