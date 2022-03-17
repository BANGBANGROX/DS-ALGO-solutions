// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
	int FindWays(int n, int m, vector<vector<int>>blockedCells) {
		// Code here
		const int mod = 1e9 + 7;

		swap(m, n);

		vector<vector<int>> grid(m, vector<int>(n));

		for (const vector<int>& blockedCell : blockedCells) {
			int x = blockedCell[0] - 1;
			int y = blockedCell[1] - 1;
			grid[x][y] = 1;
		}

		if (grid[0][0] == 1 || grid[m - 1][n - 1] == 1) return 0;

		bool blocked = false;

		for (int i = m - 1; i >= 0; --i) {
			if (grid[i][n - 1] == 1) {
				blocked = true;
				grid[i][n - 1] = 0;
			}
			if (!blocked) grid[i][n - 1] = 1;
		}

		blocked = false;

		for (int i = n - 2; i >= 0; --i) {
			if (grid[m - 1][i] == 1) {
				blocked = true;
				grid[m - 1][i] = 0;
			}
			if (!blocked) grid[m - 1][i] = 1;
		}

		for (int i = m - 2; i >= 0; --i) {
			for (int j = n - 2; j >= 0; --j) {
				if (grid[i][j] == 1) {
					grid[i][j] = 0;
					continue;
				}
				grid[i][j] = (grid[i + 1][j] + grid[i][j + 1]) % mod;
			}
		}

		return grid[0][0];
	}
};

// { Driver Code Starts.
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int n, m, k;
		cin >> n >> m >> k;
		vector<vector<int>>blocked_cells;
		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			blocked_cells.push_back({ x, y });
		}
		Solution obj;
		int ans = obj.FindWays(n, m, blocked_cells);
		cout << ans << '\n';
	}
	return 0;
}  // } Driver Code Ends