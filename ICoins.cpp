#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
int main()
{
	int n;
	cin >> n;
	vector<ld> dp(n + 1); // dp[i] probablity for i heads
	dp[0] = 1;
	for (int coin = 0; coin < n; ++coin)
	{
		ld probab;
		cin >> probab;
		for (int i = coin + 1; i > -1; --i)
		{
			dp[i] = dp[i] * (1 - probab);
			if (i > 0) dp[i] += dp[i - 1] * probab;
		}
	}
	ld res = 0;
	for (int heads = 0; heads <= n; ++heads)
	{
		int tails = (n - heads);
		if (heads > tails) res += dp[heads];
	}
	cout << setprecision(10) << fixed;
	cout << res << "\n";
	return 0;
}