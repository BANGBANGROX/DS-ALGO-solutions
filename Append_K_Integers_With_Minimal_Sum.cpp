// https://leetcode.com/problems/append-k-integers-with-minimal-sum/

#include<bits/stdc++.h>
using namespace std;

class Solution {
	typedef long long ll;
public:
	ll minimalKSum(vector<int>& nums, int k) {
		nums.insert(nums.begin(), 0);

		int n = nums.size();
		ll ans = 0;

		sort(nums.begin(), nums.end());

		for (int i = 1; i < n; ++i) {
			if (k == 0) break;
			if (nums[i] == nums[i - 1] + 1 || nums[i] == nums[i - 1]) continue;
			int terms = min(nums[i] - nums[i - 1] - 1, k);
			int a = nums[i - 1] + 1;
			ll sum = (ll)terms * (2 * (ll)a + terms - 1) / 2;
			ans += sum;
			k -= terms;
		}

		if (k > 0) {
			int a = nums[n - 1] + 1;
			ll sum = (ll)k * (2 * (ll)a + k - 1) / 2;
			ans += sum;
			k = 0;
		}

		return ans;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		vector<int> nums(n);
		for (int& x : nums) cin >> x;
		int k;
		cin >> k;

		Solution solution;
		cout << solution.minimalKSum(nums, k) << endl;
	}

	return 0;
}