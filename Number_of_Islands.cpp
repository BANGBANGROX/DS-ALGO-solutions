#include<bits/stdc++.h>
using namespace std;

int dx[4] = { 0,-1,1,0 };
int dy[4] = { -1,0,0,1 };

bool isValid(int x, int y, vector<vector<char>>& grid, vector<vector<bool>>& vis) {
	int m = grid.size(), n = grid[0].size();

	return x > -1 && x< m && y > -1 && y < n && vis[x][y] == false && grid[x][y] == '1';
}

void dfs(int x, int y, vector<vector<char>>& grid, vector<vector<bool>>& vis) {
	vis[x][y] = true;

	for (int i = 0; i < 4; ++i) {
		int newX = x + dx[i], newY = y + dy[i];
		if (isValid(newX, newY, grid, vis)) dfs(newX, newY, grid, vis);
	}
}

int numIslands(vector<vector<char>>& grid) {
	int islands = 0, m = grid.size(), n = grid[0].size();
	vector<vector<bool>> vis(m, vector<bool>(n));

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (grid[i][j] == '1' && !vis[i][j]) {
				++islands;
				dfs(i, j, grid, vis);
			}
		}
	}

	return islands;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int m, n;
		cin >> m >> n;
		vector<vector<char>> grid(m, vector<char>(n));
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> grid[i][j];
			}
		}

		cout << numIslands(grid) << endl;
	}

	return 0;
}
