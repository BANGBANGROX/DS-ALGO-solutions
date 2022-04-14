#include<bits/stdc++.h>
using namespace std;

class Solution {
	typedef long long ll;
public:
	int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
		vector<int> sortedNums(nums1.begin(), nums1.end());
		ll ans = 0;
		ll differenceSum = 0;
		int n = nums1.size();
		const int mod = 1e9 + 7;

		sort(sortedNums.begin(), sortedNums.end());

		for (int i = 0; i < n; ++i) {
			differenceSum += (ll)abs(nums1[i] - nums2[i]);
		}

		ans = differenceSum;

		for (int i = 0; i < n; ++i) {
			int idx = lower_bound(sortedNums.begin(), sortedNums.end(), nums2[i]) -
				sortedNums.begin();
			int newValue = INT_MAX;
			if (idx < n) {
				newValue = min(newValue, abs(sortedNums[idx] - nums2[i]));
			}
			if (idx > 0) {
				newValue = min(newValue, abs(sortedNums[idx - 1] - nums2[i]));
			}
			differenceSum -= (ll)abs(nums1[i] - nums2[i]);
			differenceSum += (ll)newValue;
			ans = min(ans, differenceSum);
			differenceSum -= (ll)newValue;
			differenceSum += (ll)abs(nums1[i] - nums2[i]);
		}

		return ans % mod;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		vector<int> nums1(n);
		for (int& x : nums1) cin >> x;
		vector<int> nums2(n);
		for (int& x : nums2) cin >> x;

		Solution solution;
		cout << solution.minAbsoluteSumDiff(nums1, nums2) << endl;
	}

	return 0;
}