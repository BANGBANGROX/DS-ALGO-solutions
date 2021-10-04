#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9;
int main()
{
	string a, b;
	cin >> a >> b;
	int n = a.length(), m = b.length();
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0)); // dp[i][j] is the max length subsequence after considering i letters of a and j letters of b
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (a[i] == b[j]) dp[i + 1][j + 1] = dp[i][j] + 1;
			dp[i + 1][j + 1] = max(dp[i + 1][j + 1], max(dp[i][j + 1], dp[i + 1][j]));
		}
	}
	int len = dp[n][m];
	string res("");
	int row = n, col = m;
	while (row > 0 && col > 0)
	{
		if (a[row - 1] == b[col - 1])
		{
			res = a[row - 1] + res;
			--row;
			--col;
		}
		else if (dp[row - 1][col] > dp[row][col - 1]) --row;
		else --col;
	}
	cout << res << "\n";
	return 0;
}