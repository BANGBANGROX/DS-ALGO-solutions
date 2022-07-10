// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
	typedef long long int ll;

	ll count = 0;

	void countSubsetsUtil(vector<int>& nums, int i, int l, int r, ll sum) {
		if (i == (int)nums.size()) {
			if (sum >= l && sum <= r) ++count;
			return;
		}

		countSubsetsUtil(nums, i + 1, l, r, sum + nums[i]);
		countSubsetsUtil(nums, i + 1, l, r, sum);
	}

public:
	ll countSubsets(vector<int>& arr, int n, int l, int r) {
		//Write your code here
		countSubsetsUtil(arr, 0, l, r, 0);

		return count;
	}
};

// { Driver Code Starts.
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int>arr(n);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		int l, r;
		cin >> l >> r;
		Solution ob;
		long long int ans = ob.countSubsets(arr, n, l, r);
		cout << ans << endl;
	}
	return 0;
}
// } Driver Code Ends