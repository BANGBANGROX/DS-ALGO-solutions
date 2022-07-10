#include<bits/stdc++.h>
using namespace std;

class Solution {
	vector<vector<vector<int>>> dp;
	vector<vector<int>> grid;
	int m, n;
	const vector<int> dy = { -1, 0, 1 };

	int cherryPickupUtil(int row, int col1, int col2) {
		if (row == m || col1 < 0 || col1 >= n || col2 < 0 || col2 >= n) return 0;

		if (dp[row][col1][col2] != -1) return dp[row][col1][col2];

		int ans = 0;

		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				int newCol1 = col1 + dy[i];
				int newCol2 = col2 + dy[j];
				ans = max(ans, cherryPickupUtil(row + 1, newCol1, newCol2));
			}
		}

		if (col1 == col2) ans += grid[row][col1];
		else ans += (grid[row][col1] + grid[row][col2]);

		return dp[row][col1][col2] = ans;
	}

public:
	int cherryPickup(vector<vector<int>>& grid) {
		m = grid.size();
		n = grid[0].size();
		dp = vector<vector<vector<int>>>(m, vector<vector<int>>(n, vector<int>(n, -1)));
		this->grid = grid;

		return cherryPickupUtil(0, 0, n - 1);
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int m, n;
		cin >> m >> n;
		vector<vector<int>> grid(m, vector<int>(n));
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> grid[i][j];
			}
		}

		Solution solution;
		cout << solution.cherryPickup(grid) << endl;
	}

	return 0;
}