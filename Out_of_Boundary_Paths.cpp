#include<bits/stdc++.h>
using namespace std;

class Solution {
	vector<vector<vector<int>>> dp;
	int dx[4] = { -1,0,1,0 };
	int dy[4] = { 0,-1,0,1 };
	int m;
	int n;
	const int mod = 1e9 + 7;

	int findPathsUtil(int x, int y, int maxMoves) {
		if (x < 0 || x >= m || y < 0 || y >= n) return 1;

		if (maxMoves == 0) return 0;

		if (dp[x][y][maxMoves] != -1) return dp[x][y][maxMoves];

		int ans = 0;

		for (int i = 0; i < 4; ++i) {
			ans = (ans + findPathsUtil(x + dx[i], y + dy[i], maxMoves - 1)) % mod;
		}

		return dp[x][y][maxMoves] = ans;
	}

public:
	int findPaths(int m, int n, int maxMoves, int startRow, int startColumn) {
		dp = vector<vector<vector<int>>>(m, vector<vector<int>>(n, vector<int>(maxMoves + 1, -1)));
		this->m = m;
		this->n = n;

		return findPathsUtil(startRow, startColumn, maxMoves);
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int m, n, maxMoves, startRow, startColumn;
		cin >> m >> n >> maxMoves >> startRow >> startColumn;

		Solution solution;
		cout << solution.findPaths(m, n, maxMoves, startRow, startColumn) << endl;
	}

	return 0;
}