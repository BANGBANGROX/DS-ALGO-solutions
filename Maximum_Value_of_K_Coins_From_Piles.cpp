#include<bits/stdc++.h>
using namespace std;

class Solution {
	vector<vector<int>> dp;
	int n;

	int maxValueOfCoinsUtil(vector<vector<int>>& piles, int k, int idx) {
		if (idx == n || k == 0) return 0;

		if (dp[idx][k] != -1) return dp[idx][k];

		int ans = maxValueOfCoinsUtil(piles, k, idx + 1);
		int currentSum = 0;

		for (int i = 0; i < min((int)piles[idx].size(), k); ++i) {
			currentSum += piles[idx][i];
			ans = max(ans, currentSum + maxValueOfCoinsUtil(piles, k - i - 1, idx + 1));
		}

		return dp[idx][k] = ans;
	}

public:
	int maxValueOfCoins(vector<vector<int>>& piles, int k) {
		n = piles.size();
		dp = vector<vector<int>>(n, vector<int>(k + 1, -1));

		return maxValueOfCoinsUtil(piles, k, 0);
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		vector<vector<int>> piles(n);
		for (int i = 0; i < n; ++i) {
			int m;
			cin >> m;
			piles[i] = vector<int>(m);
			for (int j = 0; j < m; ++j) {
				cin >> piles[i][j];
			}
		}
		int k;
		cin >> k;

		Solution solution;
		cout << solution.maxValueOfCoins(piles, k) << endl;
	}

	return 0;
}