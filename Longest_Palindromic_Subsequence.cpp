#include<bits/stdc++.h>
using namespace std;

int longestPalindromeSubseq(string s) {
	int n = s.size();
	vector<vector<int>> dp(n, vector<int>(n));

	for (int i = n - 1; i > -1; --i) {
		for (int j = i; j < n; ++j) {
			if (i == j) dp[i][j] = 1;
			else if (s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1] + 2;
			else dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
		}
	}

	return dp[0][n - 1];
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		string s;
		cin >> s;

		cout << longestPalindromeSubseq(s) << endl;
	}

	return 0;
}