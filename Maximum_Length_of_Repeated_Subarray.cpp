#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int findLength(vector<int>& nums1, vector<int>& nums2) {
		int m = nums1.size();
		int n = nums2.size();
		int ans = 0;
		vector<vector<int>> dp(m + 1, vector<int>(n + 1));

		for (int i = 0; i <= m; ++i) {
			for (int j = 0; j <= n; ++j) {
				if (i == 0 || j == 0) dp[i][j] = 0;
				else if (nums1[i - 1] == nums2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
				ans = max(ans, dp[i][j]);
			}
		}

		return ans;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int m;
		cin >> m;
		vector<int> nums1(m);
		for (int& x : nums1) cin >> x;
		int n;
		cin >> n;
		vector<int> nums2(n);
		for (int& x : nums2) cin >> x;

		Solution solution;
		cout << solution.findLength(nums1, nums2) << endl;
	}

	return 0;
}