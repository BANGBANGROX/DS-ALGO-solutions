#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
int dp[105][N], n, k, x;
int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> x;
		if (i > 1)
		{
			for (int j = 0; j <= k; j++)
			{
				int sum = dp[i - 1][j];
				if (j > x) sum = (sum - dp[i - 1][j - x - 1] + mod) % mod;
				dp[i][j] = sum;
			}
		}
		else for (int j = 0; j <= x; j++) dp[i][j] = 1;
		if (i < n) for (int j = 1; j <= k; j++) dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
	}
	cout << dp[n][k] << "\n";
	return 0;
}