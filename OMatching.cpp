#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int setbits(int num)
{
	int res = 0;
	while (num)
	{
		if (num & 1) ++res;
		num /= 2;
	}
	return res;
}
int main()
{
	int n;
	cin >> n;
	vector<vector<int>> can(n, vector<int>(n));
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> can[i][j];
	vector<int> dp((1 << n)); // dp[i] is the number of ways to match subset of size n
	dp[0] = 1;
	for (int mask = 0; mask < (1 << n) - 1; ++mask)
	{
		int a = setbits(mask);
		for (int b = 0; b < n; ++b)
		{
			if (can[a][b] && !(mask & (1 << b)))
			{
				int m2 = mask ^ (1 << b);
				dp[m2] = (dp[m2] + dp[mask]) % mod;
			}
		}
	}
	cout << dp[(1 << n) - 1] << "\n";
	return 0;
}
