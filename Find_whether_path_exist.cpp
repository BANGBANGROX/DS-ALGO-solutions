// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
	int dx[4] = { -1, 0, 0, 1 };
	int dy[4] = { 0, -1, 1, 0 };
	bool ans;

	void dfs(int x, int y, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
		int m = grid.size();
		int n = grid[0].size();

		if (grid[x][y] == 2) {
			ans = true;
			return;
		}

		visited[x][y] = true;

		for (int i = 0; i < 4; ++i) {
			int newX = x + dx[i];
			int newY = y + dy[i];
			if (newX >= 0 && newY >= 0 && newX < m && newY < n && !visited[newX][newY]) {
				dfs(newX, newY, grid, visited);
				if (ans) return;
			}
		}
	}
public:
	//Function to find whether a path exists from the source to destination.
	bool is_Possible(vector<vector<int>>& grid) {
		//code here
		int m = grid.size();
		int n = grid[0].size();
		int sx = -1;
		int sy = -1;
		ans = false;
		vector<vector<bool>> visited(m, vector<bool>(n));

		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (grid[i][j] == 1) {
					sx = i;
					sy = j;
				}
				if (grid[i][j] == 0) {
					visited[i][j] = true;
				}
			}
		}

		dfs(sx, sy, grid, visited);

		return ans;
	}
};

// { Driver Code Starts.
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}  // } Driver Code Ends