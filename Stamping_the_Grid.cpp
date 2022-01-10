#include<bits/stdc++.h>
using namespace std;

class Solution {
	vector<vector<int>> prefix;

	bool isPossible(int x1, int y1, int x2, int y2) {
		return (prefix[x2][y2] - (x1 > 0 ? prefix[x1 - 1][y2] : 0) - 
			(y1 > 0 ? prefix[x2][y1 - 1] : 0) + (x1 > 0 && y1 > 0 ? prefix[x1 - 1][y1 - 1] : 0)) == 0;
	}

public:
	bool possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth) {
		int m = grid.size();
		int n = grid[0].size();
		vector<vector<int>> marked(m, vector<int>(n));
		vector<vector<bool>> ans(m, vector<bool>(n));
		prefix = vector<vector<int>>(m, vector<int>(n));

		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				prefix[i][j] = grid[i][j];
				if (i == 0 && j == 0) continue;
				else if (i == 0) prefix[i][j] += prefix[i][j - 1];
				else if (j == 0) prefix[i][j] += prefix[i - 1][j];
				else prefix[i][j] += (prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1]);
			}
		}

		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (grid[i][j] == 0 && i + stampHeight <= m && j + stampWidth <= n &&
					isPossible(i, j, i + stampHeight - 1, j + stampWidth - 1)) {
					++marked[i][j];
					if (j + stampWidth < n) --marked[i][j + stampWidth];
				}
			}
		}

		for (int i = 0; i < m; ++i) {
			for (int j = 1; j < n; ++j) {
				marked[i][j] += marked[i][j - 1];
			}
		}

		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (grid[i][j] == 0 && marked[i][j] != 0) {
					ans[i][j] = true;
				}
			}
		}

		for (int j = 0; j < n; ++j) {
			for (int i = 0; i < m; ++i) {
				if (grid[i][j] == 1 || marked[i][j] == 0) continue;
				int k = i;
				while (k < m && marked[k][j] != 0) ++k;
				--k;
				int down = stampHeight;
				while (down > 0) {
					ans[k][j] = true;
					++k;
					--down;
				}
				i = k - 1;
			}
		}

		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (grid[i][j] == 0 && !ans[i][j]) return false;
			}
		}

		return true;
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
		int stampHeight, stampWidth;
		cin >> stampHeight >> stampWidth;

		Solution solution;
		if (solution.possibleToStamp(grid, stampHeight, stampWidth)) cout << "true\n";
		else cout << "false\n";
	}

	return 0;
}