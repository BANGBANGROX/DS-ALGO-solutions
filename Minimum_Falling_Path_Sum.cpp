#include<bits/stdc++.h>
using namespace std;

int minFallingPathSum(vector<vector<int>>& matrix) {
	int n = matrix.size(), ans = INT_MAX;
	vector<vector<int>> dp(matrix.begin(), matrix.end());

	for (int i = n - 2; i > -1; --i) {
		for (int j = 0; j < n; ++j) {
			int a = dp[i + 1][j], b = INT_MAX, c = INT_MAX;
			if (j > 0) b = dp[i + 1][j - 1];
			if (j < n - 1) c = dp[i + 1][j + 1];
			dp[i][j] += min(min(a, b), c);
		}
	}

	for (int x : dp[0]) ans = min(ans, x);

	return ans;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		vector<vector<int>> matrix(n, vector<int>(n));

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) cin >> matrix[i][j];
		}

		cout << minFallingPathSum(matrix) << endl;
	}

	return 0;
}
