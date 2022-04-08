#include<bits/stdc++.h>
using namespace std;

class Solution {
	typedef long long ll;

public:
	int threeSumMulti(vector<int>& nums, int target) {
		int n = nums.size();
		ll ans = 0;
		const int mod = 1e9 + 7;

		sort(nums.begin(), nums.end());

		for (int i = 0; i < n - 2; ++i) {
			if (nums[i] > target) break;
			int sum = target - nums[i];
			int l = i + 1;
			int r = n - 1;
			while (l < r) {
				int currentSum = nums[l] + nums[r];
				if (currentSum == sum) {
					int prevR = r;
					int prevL = l;
					while (r - 1 > l && nums[r] == nums[r - 1]) --r;
					while (l + 1 < r && nums[l] == nums[l + 1]) ++l;
					if (nums[l] == nums[r]) {
						int totalCount = (prevL + prevR - l - r + 2);
						ans = (ans + ((ll)totalCount * ((ll)totalCount - 1) / 2) % mod) % mod;
					}
					else {
						ans = (ans + ((prevR - r + 1) * (l - prevL + 1)) % mod) % mod;
					}
					++l;
					--r;
				}
				else if (currentSum > sum) --r;
				else ++l;
			}
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
		int target;
		cin >> target;

		Solution solution;
		cout << solution.threeSumMulti(nums, target) << endl;
	}

	return 0;
}