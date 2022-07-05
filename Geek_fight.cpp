// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
	int findPossibleKills(vector<int>& powers, int key) {
		int n = powers.size();
		int l = 0;
		int r = n - 1;
		int ans = -1;
		
		while (l <= r) {
			int mid = (l + ((r - l) >> 1));
			if (powers[mid] <= key) {
				ans = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}

		return ans;
	}

public:
	vector<pair<int, int>>win(vector<int>& powers, int n, vector<int>& queries, int q) {
		//Write your code here
		vector<int> prefixSum(n);
		vector<pair<int, int>> ans;

		sort(powers.begin(), powers.end());

		prefixSum[0] = powers[0];

		for (int i = 1; i < n; ++i) {
			prefixSum[i] = prefixSum[i - 1] + powers[i];
		}

		for (int query : queries) {
			int idx = findPossibleKills(powers, query);
			if (idx == -1) ans.push_back({ 0,0 });
			else {
				ans.push_back({ idx + 1,prefixSum[idx] });
			}
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
		vector<int>power(n);
		for (int i = 0; i < n; i++) {
			cin >> power[i];
		}
		int q;
		cin >> q;
		vector<int>Q(q);
		for (int i = 0; i < q; i++) {
			cin >> Q[i];
		}
		Solution ob;
		vector<pair<int, int>> ans = ob.win(power, n, Q, q);
		for (auto it : ans) {
			cout << it.first << " " << it.second << endl;
		}
	}
	return 0;
}
// } Driver Code Ends