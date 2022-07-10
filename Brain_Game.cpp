// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool brainGame(vector<int>& nums) {
		// Code here.
		const int MAX_N = *max_element(nums.begin(), nums.end()) + 1;
		vector<int> dp(MAX_N);
		int ans = 0;

		for (int i = 2; i < MAX_N; ++i) {
			for (int j = 2 * i; j < MAX_N; j += i) {
				dp[j] = max(dp[j], 1 + dp[i]);
			}
		}

		for (int num : nums) {
			ans ^= dp[num];
		}

		return ans != 0;
	}
};

// { Driver Code Starts.
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<int>nums(n);
		for (int i = 0; i < n; i++)cin >> nums[i];
		Solution ob;
		bool ans = ob.brainGame(nums);
		if (ans)
			cout << "A\n";
		else cout << "B\n";
	}
	return 0;
}  // } Driver Code Ends