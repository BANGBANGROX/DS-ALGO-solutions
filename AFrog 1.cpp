#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N], dp[N], n;
int findmincost(int ind)
{
	if (ind == n) return 0;
	if (dp[ind] != -1) return dp[ind];
	int res = INT_MAX;
	res = min(res, findmincost(ind + 1) + abs(a[ind] - a[ind + 1]));
	if (ind + 2 <= n) res = min(res, findmincost(ind + 2) + abs(a[ind] - a[ind + 2]));
	return dp[ind] = res;
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i], dp[i] = -1;
	cout << findmincost(1) << "\n";
	return 0;
}