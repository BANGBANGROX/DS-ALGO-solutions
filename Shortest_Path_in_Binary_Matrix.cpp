#include<bits/stdc++.h>
using namespace std;

int dx[8] = { -1,-1,0,1,1,1,0,-1 };
int dy[8] = { 0,1,1,1,0,-1,-1,-1 };

bool isValid(vector<vector<int>>& grid, int x, int y) {
	int m = grid.size(), n = grid[0].size();

	return x < m && x > -1 && y < n && y > -1 && grid[x][y] == 0;
}

int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
	int m = grid.size(), n = grid[0].size(), length = 0;
	queue<pair<int, int>> q;

	if (grid[0][0] == 1) return -1;

	q.push({ 0,0 });
	grid[0][0] = 1;

	while (!q.empty()) {
		int size = q.size();
		++length;
		while (size--) {
			pair<int, int> curr = q.front();
			q.pop();
			int x = curr.first, y = curr.second;
			if (x == m - 1 && y == n - 1) return length;
			for (int i = 0; i < 8; ++i) {
				int newX = x + dx[i], newY = y + dy[i];
				if (isValid(grid, newX, newY)) {
					q.push({ newX,newY });
					grid[newX][newY] = 1;
				}
			}
		}
	}

	return -1;
}

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

		cout << shortestPathBinaryMatrix(grid) << endl;
	}

	return 0;
}