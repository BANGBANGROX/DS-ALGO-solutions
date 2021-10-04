#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e18;
int main()
{
	int n;
	cin >> n;
	vector<ll> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];
	vector<vector<ll>> dp(n, vector<ll>(n, inf));
	for (int i = 0; i < n; i++)
	{
		if (i) arr[i] += arr[i - 1];
		dp[i][i] = 0;
	}
	for (int len = 2; len <= n; len++)
	{
		for (int i = 0; i + len <= n; i++)
		{
			int ind = i + len - 1;
			ll sum = arr[ind];
			if (i) sum -= arr[i - 1];
			for (int j = i; j < ind; j++)
				dp[i][ind] = min(dp[i][ind], dp[i][j] + dp[j + 1][ind] + sum);
		}
	}
	cout << dp[0][n - 1] << "\n";
	return 0; // O(n^3) in worst case 
}