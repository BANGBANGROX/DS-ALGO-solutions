//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	int countTriplets(vector<int>& nums) {
		// Code here.
		int n = (int)nums.size();
		int ans = 0;
		
		for (int i = 1; i < n - 1; ++i) {
			int smaller = 0;
			int larger = 0;
			for (int j = i - 1; j >= 0; --j) {
				if (nums[j] < nums[i]) ++smaller;
			}
			for (int j = i + 1; j < n; ++j) {
				if (nums[j] > nums[i]) ++larger;
			}
			ans += smaller * larger;
		}

		return ans;
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
		for (int i = 0; i < n; i++) {
			cin >> nums[i];
		}
		Solution ob;
		int ans = ob.countTriplets(nums);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends