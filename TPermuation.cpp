#include<bits/stdc++.h>
using namespace std;
const int N = 3005;
const int mod = 1e9 + 7;
int dp[N][N], pref[N][N], n;
// dp[i][j] stores the result for prefix of length i and ending in position j
void add_self(int& a, int b)
{
	a += b;
	if (a >= mod) a -= mod;
}
int main()
{
	string s;
	cin >> n >> s;
	dp[1][1] = 1;
	for (int len = 2; len <= n; ++len)
	{
		for (int i = 1; i < len; ++i) pref[len - 1][i] = (dp[len - 1][i] + pref[len - 1][i - 1]) % mod;
		for (int b = 1; b <= n; ++b)
		{
			int L, R;
			if (s[len - 2] == '<')
			{
				L = 1;
				R = b - 1;
			}
			else
			{
				L = b;
				R = len - 1;
			}
			add_self(dp[len][b], (pref[len - 1][R] - pref[len - 1][L - 1] + mod) % mod);
		}
	}
	int res = 0;
	for (int i = 1; i <= n; ++i)
		add_self(res, dp[n][i]);
	cout << res << "\n";
	return 0;
}