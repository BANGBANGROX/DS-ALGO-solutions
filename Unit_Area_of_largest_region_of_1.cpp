//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	const int dx[8] = { -1,-1,0,1,1,1,0,-1 };
	const int dy[8] = { 0,1,1,1,0,-1,-1,-1 };
	int m;
	int n;

	void dfs(vector<vector<int>>& grid, int x, int y, int* count) {
		if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 0) return;

		*count = *count + 1;
		grid[x][y] = 0;

		for (int i = 0; i < 8; ++i) {
			dfs(grid, x + dx[i], y + dy[i], count);
		}
	}

public:
	//Function to find unit area of the largest region of 1s.
	int findMaxArea(vector<vector<int>>& grid) {
		// Code here
		m = grid.size();
		n = grid[0].size();
		int ans = 0;

		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (grid[i][j] == 1) {
					int count = 0;
					dfs(grid, i, j, &count);
					ans = max(ans, count);
				}
			}
		}

		return ans;
	}
};

//{ Driver Code Starts.
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends