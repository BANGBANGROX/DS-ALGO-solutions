#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<int> dp(3);
	for (int day = 0; day < n; day++)
	{
		vector<int> new_dp(3);
		vector<int> cost(3);
		for (int i = 0; i < 3; i++) cin >> cost[i];
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; ++j)
				if (i != j)
					new_dp[j] = max(new_dp[j], dp[i] + cost[j]);
		}
		dp = new_dp;
	}
	cout << max(dp[0], max(dp[1], dp[2])) << "\n"; // Errichto OP
	return 0;
}