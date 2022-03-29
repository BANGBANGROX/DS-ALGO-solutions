#include<bits/stdc++.h>
using namespace std;

class Solution {
	int minLength;
	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };

	void dfs(int x, int y, int dr, int dc, int length, vector<vector<bool>>&visited, 
		vector<vector<int>>&grid) {
		if (x == dr && y == dc) {
			minLength = min(minLength, length);
			return;
		}

		int m = grid.size();
		int n = grid[0].size();

		visited[x][y] = true;

		for (int i = 0; i < 4; ++i) {
			int newX = x + dx[i];
			int newY = y + dy[i];
			if (newX >= 0 && newY >= 0 && newX < m && newY < n && grid[newX][newY] == 0 && 
				!visited[newX][newY]) {
				dfs(newX, newY, dr, dc, length + 1, visited, grid);
			}
		}

		visited[x][y] = false;
	}

public:
        // TC O(m ^ n)
        // SC O(m * n) 
	int findMinPathLength(vector<vector<int>>& grid, int sr, int sc, int dr, int dc) {
		minLength = INT_MAX;
		int m = grid.size();
		int n = grid[0].size();
		vector<vector<bool>> visited(m, vector<bool>(n));

		dfs(sr, sc, dr, dc, 1, visited, grid);

		return minLength;
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
		int sr, sc, dr, dc;
		cin >> sr >> sc >> dr >> dc;

		Solution solution;
		cout << solution.findMinPathLength(grid, sr, sc, dr, dc) << endl;
	}

	return 0;
}