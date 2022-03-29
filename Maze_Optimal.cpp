#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	// TC O(m * n)
	// SC O(m * n)
	int findMinPathLength(vector<vector<int>>& grid, int sr, int sc, int dr, int dc) {
		int length = 1;
		int m = grid.size();
		int n = grid[0].size();
		int dx[4] = { 1,0,-1,0 };
		int dy[4] = { 0,1,0,-1 };
		vector<vector<int>> distance(m, vector<int>(n, INT_MAX));
		queue<pair<int, int>> q;

		q.push({ sr,sc });
		distance[sr][sc] = 0;

		while (!q.empty()) {
			int size = q.size();
			for (int tc = 0; tc < size; ++tc) {
				int x = q.front().first;
				int y = q.front().second;
				q.pop();
				for (int i = 0; i < 4; ++i) {
					int newX = x + dx[i];
					int newY = y + dy[i];
					if (newX >= 0 && newY >= 0 && newX < m && newY < n && grid[newX][newY] == 0
						&& distance[newX][newY] > 1 + distance[x][y]) {
						distance[newX][newY] = 1 + distance[x][y];
						if (newX == dr && newY == dc) return length;
						q.push({ newX,newY });
					}
				}
			}
			++length;
		}

		return -1;
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