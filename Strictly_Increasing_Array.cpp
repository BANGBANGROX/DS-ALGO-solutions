//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	int min_operations(vector<int>& nums) {
		// Code here
		vector<int> dp;
		int n = nums.size();

		for (int i = 0; i < n; ++i) {
			nums[i] -= i;
		}

		dp.push_back(nums[0]);

		for (int i = 1; i < n; ++i) {
			int idx = upper_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
			if (idx == (int)dp.size()) dp.push_back(nums[i]);
			else dp[idx] = nums[i];
		}

		return n - (int)dp.size();
	}
};

//{ Driver Code Starts.
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<int>nums(n);
		for (int i = 0; i < n; i++)cin >> nums[i];
		Solution ob;
		int ans = ob.min_operations(nums);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends