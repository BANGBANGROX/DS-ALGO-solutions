// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
	vector<vector<int>> dp;
	vector<vector<int>> cost;
	int n;
	const int MAX_N = (1 << 10);

	int totalCostUtil(int node, int mask) {
		if (mask == (1 << n) - 1) return 0;

		if (dp[node][mask] != -1) return dp[node][mask];

		int ans = INT_MAX;

		for (int i = 0; i < n; ++i) {
			if ((mask & (1 << i)) > 0) continue;
			ans = min(ans, totalCostUtil(i, mask | (1 << i)));
		}

		return dp[node][mask] = ans;
	}

public:
	int total_cost(vector<vector<int>>cost) {
		// Code here
		n = cost.size();
		this->cost = cost;
		dp = vector<vector<int>>(n, vector<int>(MAX_N, -1));

		return totalCostUtil(0, 1);
	}
};

// { Driver Code Starts.
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<vector<int>>cost(n, vector<int>(n, 0));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)cin >> cost[i][j];
		Solution obj;
		int ans = obj.total_cost(cost);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends