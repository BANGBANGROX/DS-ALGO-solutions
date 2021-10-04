#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main()
{
	int n, k;
	cin >> n >> k;
	vector<vector<int>> dp(n, vector<int>(k + 1, 0));
	for (int child = 0; child < n; ++child)
	{
		int capacity;
		cin >> capacity;
		if (child == 0) for (int i = 0; i <= capacity; ++i) dp[child][i] = 1;
		else
		{
			for (int i = 0; i <= k; ++i)
			{
				int sum = dp[child - 1][i];
				if (i > capacity) sum = (sum - dp[child - 1][i - capacity - 1] + mod) % mod;
				dp[child][i] = sum;
			}
		}
		if (child < (n - 1))
		{
			for (int i = 1; i <= k; ++i) dp[child][i] = (dp[child][i] + dp[child][i - 1]) % mod;
		}
	}
	cout << dp[n - 1][k] << "\n";
	return 0;
}

