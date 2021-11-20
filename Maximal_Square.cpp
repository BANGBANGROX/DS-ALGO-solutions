#include<bits/stdc++.h>
using namespace std;

int maximalSquare(vector<vector<char>>& matrix) {
	int m = matrix.size(), n = matrix[0].size(), maxLen = 0;
	vector<vector<int>> dp(m + 1, vector<int>(n + 1)); 
	//dp[i][j] is the length of the largest square whose bottom right vertex is matrix[i][j]

	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (matrix[i - 1][j - 1] == '1') {
				dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
				maxLen = max(maxLen, dp[i][j]);
			}
		}
	}

	return maxLen * maxLen;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int m, n;
		cin >> m >> n;
		vector<vector<char>> matrix(m, vector<char>(n));
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) cin >> matrix[i][j];
		}

		cout << maximalSquare(matrix) << endl;
	}
}
