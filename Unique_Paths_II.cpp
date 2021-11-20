#include<bits/stdc++.h>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
	int m = obstacleGrid.size(), n = obstacleGrid[0].size();
	vector<vector<int>> dp(m, vector<int>(n));

	if (obstacleGrid[0][0] || obstacleGrid[m - 1][n - 1]) return 0;

	for (int i = n - 1; i > -1; --i) {
		if (obstacleGrid[m - 1][i]) break;
		dp[m - 1][i] = 1;
	}
	for (int i = m - 1; i > -1; --i) {
		if (obstacleGrid[i][n - 1]) break;
		dp[i][n - 1] = 1;
	}

	for (int i = m - 2; i > -1; --i) {
		for (int j = n - 2; j > -1; --j) {
			if (!obstacleGrid[i][j]) dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
		}
	}

	return dp[0][0];
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int m, n;
		cin >> m >> n;
		vector<vector<int>> obstacleGrid(m, vector<int>(n));
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) cin >> obstacleGrid[i][j];
		}

		cout << uniquePathsWithObstacles(obstacleGrid) << endl;
	}

	return 0;
}
