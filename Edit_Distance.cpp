#include<bits/stdc++.h>
using namespace std;

int minDistance(string word1, string word2) {
	int n = word1.size(), m = word2.size();

	vector<vector<int>> dp(n + 1, vector<int>(m + 1));

	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= m; ++j) {
			if (i == 0) dp[i][j] = j;
			else if (j == 0) dp[i][j] = i;
			else if (word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
			else dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
		}
	}

	return dp[n][m];
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		string word1, word2;
		cin >> word1 >> word2;

		cout << minDistance(word1, word2) << endl;
	}

	return 0;
}
