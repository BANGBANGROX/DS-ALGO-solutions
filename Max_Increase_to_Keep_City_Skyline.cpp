#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
		int n = grid.size();
		int ans = 0;
		vector<int> rowMax(n);
		vector<int> colMax(n);

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				rowMax[i] = max(rowMax[i], grid[i][j]);
				colMax[j] = max(colMax[j], grid[i][j]);
			}
		}

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				ans += (min(rowMax[i], colMax[j]) - grid[i][j]);
			}
		}

		return ans;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		vector<vector<int>> grid(n, vector<int>(n));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> grid[i][j];
			}
		}

		Solution solution;
		cout << solution.maxIncreaseKeepingSkyline(grid) << endl;
	}

	return 0;
}