#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int numRows) {
	vector<vector<int>> dp(numRows, vector<int>(numRows)), ans(numRows);

	for (int i = 0; i < numRows; ++i) {
		for (int j = 0; j < numRows; ++j) {
			if (i < j) continue;
			if (i == j || j == 0) dp[i][j] = 1;
			else dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
		}
	}

	for (int i = 0; i < numRows; ++i) {
		for (int j = 0; j < numRows; ++j) {
			if (dp[i][j] > 0) ans[i].push_back(dp[i][j]);
		}
	}

	return ans;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int numRows;
		cin >> numRows;

		vector<vector<int>> ans = generate(numRows);

		for (vector<int> x : ans) {
			for (int y : x) cout << y << " ";
			cout << endl;
		}
	}

	return 0;
}