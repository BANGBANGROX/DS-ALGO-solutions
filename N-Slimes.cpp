#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e18;
int main()
{
	int n;
	cin >> n;
	vector<ll> a(n);
	for (ll& x : a) cin >> x;
	vector<vector<ll>> dp(n, vector<ll>(n, inf)); // dp[i][j] is the ans for the partition i to j
	for (int i = 0; i < n; ++i)
	{
		dp[i][i] = 0;
		if (i) a[i] += a[i - 1];
	}
	ll 
	for (int len = 2; len <= n; ++len)
	{
		for (int left = 0; left + len <= n; ++left)
		{
			int right = (len + left - 1); // partition left to right 
			ll sum = a[right]; // initially result prefix sum till right
			if (left) sum -= a[left - 1];
			for (int part = left; part < right; ++part)
				dp[left][right] = min(dp[left][part] + dp[part + 1][right] + sum, dp[left][right]);
		}
	}
	cout << dp[0][n - 1] << "\n";
	return 0;
}