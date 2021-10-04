#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
int main()
{
	int n, w;
	cin >> n >> w;
	vector<ll> dp(w + 1);
	for (int item = 0; item < n; ++item)
	{
		int weight, value;
		cin >> weight >> value;
		for (int weight_already = w - weight; weight_already > -1; --weight_already)
			dp[weight_already + weight] = max(dp[weight_already + weight], dp[weight_already] + value);
	}
	ll res = 0;
	for (int i = 1; i <= w; ++i) res = max(res, dp[i]);
	cout << res << "\n";
	return 0;
}