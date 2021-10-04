#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e18;
int main()
{
	int n, w;
	cin >> n >> w;
	vector<int> weight(n), value(n);
	for (int i = 0; i < n; ++i) cin >> weight[i] >> value[i];
	int sum_value = 0;
	for (int x : value) sum_value += x;
	vector<ll> dp(sum_value + 1, inf); // dp[i] = min wt for value sum i
	dp[0] = 0; // for 0 value weight 0 is min
	for (int item = 0; item < n; ++item)
	{
		int val = value[item], wt = weight[item];
		for (int value_used = sum_value - val; value_used > -1; --value_used)
			dp[value_used + val] = min(dp[value_used + val], dp[value_used] + wt);
	}
	int res = 0;
	for (int i = sum_value; i > -1; --i)
	{
		if (dp[i] <= w)
		{
			res = i;
			break;
		}
	}
	cout << res << "\n";
	return 0;
}