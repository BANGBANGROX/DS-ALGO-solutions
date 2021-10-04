#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
char grid[1005][1005];
int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0)); // dp[i][j] is the number of ways to reach (n,m) from (i,j)
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
			cin >> grid[i][j];
	}
	for (int i = m; i > 0; --i)
	{
		if (grid[n][i] == '.') dp[n][i] = 1;
		else break;
	}
	for (int i = n; i > 0; --i)
	{
		if (grid[i][m] == '.') dp[i][m] = 1;
		else break;
	}
	for (int i = n - 1; i > 0; --i)
	{
		for (int j = m - 1; j > 0; --j)
		{
			if (grid[i][j] == '.') dp[i][j] = (dp[i + 1][j] + dp[i][j + 1]) % mod;
		}
	}
	cout << dp[1][1] << "\n";
	return 0;
}
