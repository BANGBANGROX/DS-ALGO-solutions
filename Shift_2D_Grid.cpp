#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
		vector<int> flattenedGrid;
		int m = grid.size();
		int n = grid[0].size();
		int ptr = 0;

		k %= (m * n);

		if (k == 0) return grid;

		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				flattenedGrid.push_back(grid[i][j]);
			}
		}

		k = m * n - k;

		reverse(flattenedGrid.begin(), flattenedGrid.begin() + k);
		reverse(flattenedGrid.begin() + k, flattenedGrid.end());
		reverse(flattenedGrid.begin(), flattenedGrid.end());

		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				grid[i][j] = flattenedGrid[ptr++];
			}
		}

		return grid;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {

	}

	return 0;
}