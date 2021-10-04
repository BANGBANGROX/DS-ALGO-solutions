#include<bits/stdc++.h>
using namespace std;

bool isValid(int x, int y, int n, int m) {
	return x >= 0 && y >= 0 && x < n && y < m;
}

void bfs(vector<vector<int>>& grid, vector<vector<int>>&dist) {
	int n = grid.size(), m = grid[0].size();
	int dx[] = { -1,0,0,1 };
	int dy[] = { 0,-1,1,0 };
	queue<pair<int, int>> q;
	vector<vector<bool>> vis(n, vector<bool>(m));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (grid[i][j] == 1) {
				dist[i][j] = 0;
				q.push({ i,j });
			}
		}
	}

	while (!q.empty()) {
		pair<int, int> top = q.front();
		q.pop();
		int x = top.first;
		int y = top.second;
		vis[x][y] = 1;
		for (int i = 0; i < 4; ++i) {
			if (isValid(x + dx[i], y + dy[i], n, m) && !vis[x + dx[i]][y + dy[i]]) {
				int newX = x + dx[i];
				int newY = y + dy[i];
				dist[newX][newY] = min(dist[newX][newY], 1 + dist[x][y]);
				q.push({ newX, newY });
			}
		}
	}
}

vector<vector<int>>nearest(vector<vector<int>>grid) {
	int n = grid.size(), m = grid[0].size();

	vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

	bfs(grid, dist);

	return dist;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>> grid(n, vector<int>(m));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cin >> grid[i][j];
			}
		}

		vector<vector<int>> dist = nearest(grid);

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cout << dist[i][j] << " ";
			}
			cout << endl;
		}
	}

	return 0;
}