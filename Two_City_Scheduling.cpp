#include<bits/stdc++.h>
using namespace std;

class Solution {
	vector<vector<int>> dp;

	int twoCitySchedCostUtil(vector<vector<int>>& costs, int index, int sizeA) {
		if (index == costs.size()) return 0;

		if (dp[index][sizeA] != -1) return dp[index][sizeA];

		int ans = INT_MAX;
		int maxSize = costs.size() / 2;
		int sizeB = index - sizeA;

		// Lets try to send candidate "index" to city A if possible
		if (sizeA < maxSize) 
			ans = costs[index][0] + twoCitySchedCostUtil(costs, index + 1, sizeA + 1);

		// Lets try to send candidate "index" to city B if possible
		if (sizeB < maxSize)
			ans = min(ans, costs[index][1] + twoCitySchedCostUtil(costs, index + 1, sizeA));

		return dp[index][sizeA] = ans;
	}

public:
	int twoCitySchedCost(vector<vector<int>>& costs) {
		int n = costs.size();

		dp = vector<vector<int>>(n, vector<int>(n, -1));

		return twoCitySchedCostUtil(costs, 0, 0);
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		vector<vector<int>> costs(n, vector<int>(2));
		for (int i = 0; i < n; ++i) {
			cin >> costs[i][0] >> costs[i][1];
		}

		Solution solution;
		cout << solution.twoCitySchedCost(costs) << endl;
	}

	return 0;
}