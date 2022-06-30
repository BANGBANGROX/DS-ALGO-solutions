// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
	vector<int>kthSmallestNum(vector<vector<int>>& range, vector<int>queries) {
		//Write your code here
		const int MAX_RANGE = 2005;
		vector<int> count(MAX_RANGE);
		vector<int> ans;
		vector<int> nums;

		for (vector<int>& currentRange : range) {
			int l = currentRange[0];
			int r = currentRange[1] + 1;
			++count[l];
			--count[r];
		}

		for (int i = 1; i < MAX_RANGE; ++i) {
			count[i] += count[i - 1];
			if (count[i] > 0) nums.push_back(i);
		}

		for (int q : queries) {
			if (q - 1 < (int)nums.size()) ans.push_back(nums[q - 1]);
			else ans.push_back(-1);
		}

		return ans;
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
		vector<vector<int>>range(n, vector<int>(2, 0));
		for (int i = 0; i < n; i++) {
			cin >> range[i][0] >> range[i][1];
		}
		int q;
		cin >> q;
		vector<int>queries;
		for (int i = 0; i < q; i++) {
			int x;
			cin >> x;
			queries.push_back(x);
		}
		Solution ob;
		vector<int>ans = ob.kthSmallestNum(range, queries);
		for (auto it : ans) {
			cout << it << " ";
		}
		cout << endl;
	}
	return 0;
}
// } Driver Code Ends