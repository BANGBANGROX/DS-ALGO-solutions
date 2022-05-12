// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	void sortedArrayToBSTUtil(int l, int r, vector<int>& nums, vector<int>& ans) {
		if (l > r) return;

		int mid = (l + ((r - l) >> 1));

		ans.push_back(nums[mid]);

		sortedArrayToBSTUtil(l, mid - 1, nums, ans);
		sortedArrayToBSTUtil(mid + 1, r, nums, ans);
	}

public:
	vector<int> sortedArrayToBST(vector<int>& nums) {
		// Code here
		vector<int> ans;
		int n = nums.size();

		sortedArrayToBSTUtil(0, n - 1, nums, ans);

		return ans;
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
		Solution obj;
		vector<int>ans = obj.sortedArrayToBST(nums);
		for (auto i : ans)
			cout << i << " ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends