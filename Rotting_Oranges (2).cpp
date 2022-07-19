#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int orangesRotting(vector<vector<int>>& grid) {
		int m = grid.size();
		int n = grid[0].size();
		int ans = 0;
		int dx[4] = { -1,0,0,1 };
		int dy[4] = { 0,1,-1,0 };
		queue<pair<int, int>> q;

		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (grid[i][j] == 2) q.push({ i,j });
			}
		}

		while (!q.empty()) {
			int size = q.size();
			for (int i = 0; i < size; ++i) {
				pair<int, int> currentCell = q.front();
				q.pop();
				int x = currentCell.first;
				int y = currentCell.second;
				for (int j = 0; j < 4; ++j) {
					int newX = x + dx[j];
					int newY = y + dy[j];
					if (newX >= 0 && newX < m && newY >= 0 && newY < n && grid[newX][newY] == 1) {
						grid[newX][newY] = 2;
						q.push({ newX,newY });
					}
				}
			}
			++ans;
		}

		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (grid[i][j] == 1) return -1;
			}
		}

		return ans;
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

		Solution solution;
		cout << solution.orangesRotting(grid);
	}

	return 0;
}