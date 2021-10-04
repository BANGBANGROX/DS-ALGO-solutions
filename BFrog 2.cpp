#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N], dp[N], n, k;
int findmincost(int ind)
{
	if (ind == n) return 0;
	if (dp[ind] != -1) return dp[ind];
	int res = INT_MAX;
	for (int i = 1; i <= k; i++)
		if (ind + i <= n) res = min(res, findmincost(ind + i) + abs(a[ind] - a[ind + i]));
	return dp[ind] = res;
}
int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	memset(dp, -1, sizeof(dp));
	cout << findmincost(1) << "\n";
	return 0;
}
