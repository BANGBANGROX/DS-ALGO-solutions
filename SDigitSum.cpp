#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
void add(int& a, int b)
{
	a = (a + b) % mod;
}
int main()
{
	string k;
	int D;
	cin >> k >> D;
	int len = k.length();
	vector<vector<int>> dp(D, vector<int>(2)); 
	// dp[i][j] is the number of ways to choose numbers whose sum of digits % D is i and j will be 0 if we choose any digit greater than
	// the corresponding digit of k
	dp[0][0] = 1;
	for (int pos = 0; pos < len; ++pos)
	{
		vector<vector<int>> curr_dp(D, vector<int>(2));
		for (int sum = 0; sum < D; ++sum)
		{
			for (bool smaller : {0, 1})
			{
				for (int digit = 0; digit < 10; ++digit)
				{
					if (digit > k[pos] - '0' && !smaller) break;
					add(curr_dp[(sum + digit) % D][smaller || (digit < (k[pos] - '0'))], dp[sum][smaller]);
				}
			}
		}
		dp = curr_dp;
	}
	int res = (dp[0][1] + dp[0][0] - 1 + mod) % mod;
	cout << res << "\n";
	return 0;
}
