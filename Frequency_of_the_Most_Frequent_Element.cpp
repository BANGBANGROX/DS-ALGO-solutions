#include<bits/stdc++.h>
using namespace std;

class Solution {
	typedef long long ll;
public:
	int maxFrequency(vector<int>& nums, int k) {
		int n = nums.size();
		int ans = 1;
		int j = 0;
		ll count = 0;

		sort(nums.begin(), nums.end());

		for (int i = 1; i < n; ++i) {
			count += ((ll)nums[i] - nums[i - 1]) * ((ll)i - j);
			while (count > k) {
				count -= ((ll)nums[i] - nums[j]);
				++j;
			}
			ans = max(ans, i - j + 1);
		}

		return ans;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n, k;
		cin >> n;
		vector<int> nums(n);
		for (int& x : nums) cin >> x;
		cin >> k;

		Solution solution;
		cout << solution.maxFrequency(nums, k) << endl;
	}

	return 0;
}