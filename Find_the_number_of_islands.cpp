#include<bits/stdc++.h>
using namespace std;

int dx[] = { 0,1,1,1,0,-1,-1,-1 };
int dy[] = { 1,1,0,-1,-1,-1,0,1 };

bool isValid(int x, int y, int n, int m) {
	return x >= 0 && y >= 0 && x < n && y < m;
}

void dfs(int x, int y, vector<vector<char>>& grid, vector<vector<bool>>& vis) {
	int n = grid.size(), m = grid[0].size();
	vis[x][y] = 1;

	for (int i = 0; i < 4; ++i) {
		int newX = x + dx[i];
		int newY = y + dy[i];
		if (isValid(newX, newY, n, m) && !vis[newX][newY] && grid[newX][newY] == '1') {
			vis[newX][newY] = 1;
			dfs(newX, newY, grid, vis);
		}
	}
}

int numIslands(vector<vector<char>>& grid) {
	int n = grid.size(), m = grid[0].size();
	vector<vector<bool>> vis(n, vector<bool>(m));
	int cc = 0;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (grid[i][j] == '0' || vis[i][j]) continue;
			dfs(i, j, grid, vis);
			++cc;
		}
	}

	return cc;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		vector<vector<char>> grid(n, vector<char>(m));

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) cin >> grid[i][j];
		}

		cout << numIslands(grid) << endl;
	}

	return 0;
}