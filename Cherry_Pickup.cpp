#include<bits/stdc++.h>
using namespace std;

int findTotal(vector<vector<int>>& grid, vector<vector<vector<int>>>& dp, int x1, int x2, int y1) {
	int y2 = x1 + y1 - x2;
	int n = grid.size();

	if (x1 == n - 1 && x2 == n - 1 && y1 == n - 1) {
		return dp[x1][y1][x2] = grid[x1][y1];
	}

	if (x1 > n - 1 || y1 > n - 1 || x2 > n - 1 || y2 > n - 1) {
		return -1;
	}

	if (grid[x1][y1] == -1 || grid[x2][y2] == -1) {
		dp[x1][y1][x2] = -1;
		return -1;
	}

	if (dp[x1][y1][x2] != -2) return dp[x1][y1][x2];

	int val1 = grid[x1][y1];
	int val2 = grid[x2][y2];
	grid[x1][y1] = 0;
	grid[x2][y2] = 0;

	int a = findTotal(grid, dp, x1, x2 + 1, y1 + 1);

	int b = findTotal(grid, dp, x1, x2, y1 + 1);

	int c = findTotal(grid, dp, x1 + 1, x2, y1);

	int d = findTotal(grid, dp, x1 + 1, x2 + 1, y1);

	grid[x1][y1] = val1;
	grid[x2][y2] = val2;

	if (a == -1 && b == -1 && c == -1 && d == -1) {
		dp[x1][y1][x2] = -1;
		return -1;
	}

	if (x1 == x2 && y1 == y2) {
		dp[x1][y1][x2] = val1 + max(a, max(max(b, c), d));
		return dp[x1][y1][x2];
	}

	dp[x1][y1][x2] = val1 + val2 + max(a, max(max(b, c), d));
	return dp[x1][y1][x2];
}

int cherryPickup(vector<vector<int>>& grid) {
	int n = grid.size();
	vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, -2)));

	int ans = findTotal(grid, dp, 0, 0, 0);
	if (ans == -1) ans = 0;

	return ans;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<vector<int>> a(n, vector<int>(n));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> a[i][j];
			}
		}

		cout << cherryPickup(a) << endl;
	}
}