#include<bits/stdc++.h>
using namespace std;

class Solution {
	vector<vector<bool>> pacificAtlanticUtil(vector<vector<int>>& heights, bool flag) {
		int m = heights.size();
		int n = heights[0].size();
		int dx[4] = { -1,0,0,1 };
		int dy[4] = { 0,1,-1,0 };
		queue<pair<int, int>> q;
		vector<vector<bool>> ans(m, vector<bool>(n));
		
		if (flag) { // Top Left
			for (int i = 0; i < n; ++i) {
				q.push({ 0,i });
				ans[0][i] = true;
			}
			for (int i = 0; i < m; ++i) {
				q.push({ i,0 });
				ans[i][0] = true;
			}
		}
		else { // Bottom Right
			for (int i = 0; i < m; ++i) {
				q.push({ i,n - 1 });
				ans[i][n - 1] = true;
			}
			for (int i = 0; i < n; ++i) {
				q.push({ m - 1,i });
				ans[m - 1][i] = true;
			}
		}

		while (!q.empty()) {
			pair<int, int> currentCell = q.front();
			q.pop();
			int x = currentCell.first;
			int y = currentCell.second;
			for (int i = 0; i < 4; ++i) {
				int newX = x + dx[i];
				int newY = y + dy[i];
				if (newX >= 0 && newX < m && newY >= 0 && newY < n && 
					heights[newX][newY] >= heights[x][y] && !ans[newX][newY]) {
					ans[newX][newY] = true;
					q.push({ newX,newY });
				}
			}
		}

		return ans;
	}

public:
	vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
		vector<vector<bool>> topLeft = pacificAtlanticUtil(heights, true);
		vector<vector<bool>> bottomRight = pacificAtlanticUtil(heights, false);
		vector<vector<int>> ans;
		int m = heights.size();
		int n = heights[0].size();

		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (topLeft[i][j] && bottomRight[i][j]) {
					ans.push_back({ i,j });
				}
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
		vector<vector<int>> heights(m, vector<int>(n));
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> heights[i][j];
			}
		}

		Solution solution;
		vector<vector<int>> ans = solution.pacificAtlantic(heights);
		for (vector<int>& x : ans) {
			for (int& y : x) cout << y << " ";
			cout << endl;
		}
	}

	return 0;
}