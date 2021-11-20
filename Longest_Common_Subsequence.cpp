#include<bits/stdc++.h>
using namespace std;

int longestCommonSubsequence(string text1, string text2) {
	int n = text1.size(), m = text2.size();
	vector<vector<int>> dp(n + 1, vector<int>(m + 1));

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (text1[i - 1] == text2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], max(dp[i - 1][j - 1], dp[i][j - 1]));
		}
	}

	return dp[n][m];
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		string text1, text2;
		cin >> text1 >> text2;

		cout << longestCommonSubsequence(text1, text2) << endl;
	}

	return 0;
}