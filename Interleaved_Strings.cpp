#include<bits/stdc++.h>
using namespace std;

bool isInterleaved(string a, string b, string c) {
	int m = a.size(), n = b.size();
	if (m + n != (int)c.size()) return false;

	vector<vector<bool>> dp(m + 1, vector<bool>(n + 1)); // dp[i][j] is true if c[0...i+j-1] is interleaved using a[0...i-1] and b[0...j-1]

	for (int i = 0; i <= m; ++i) {
		for (int j = 0; j <= n; ++j) {
			if (i == 0 && j == 0) {
				dp[i][j] = 1;
			}
			else if (i == 0) {
				if (c[i + j - 1] == b[j - 1]) {
					dp[i][j] = dp[i][j - 1];
				}
			}
			else if (j == 0) {
				if (c[i + j - 1] == a[i - 1]) {
					dp[i][j] = dp[i - 1][j];
				}
			}
			else {
				if (a[i - 1] != c[i + j - 1]) {
					if (b[j - 1] == c[i + j - 1]) {
						dp[i][j] = dp[i][j - 1];
					}
				}
				else if (b[j - 1] != c[i + j - 1]) {
					if (a[i - 1] == c[i + j - 1]) {
						dp[i][j] = dp[i - 1][j];
					}
				}
				else {
					dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
				}
			}
		}
	}

	return dp[m][n];
}

int main() {
	string a, b, c;
	cin >> a >> b >> c;

	cout << isInterleaved(a, b, c) << endl;

	return 0;
}