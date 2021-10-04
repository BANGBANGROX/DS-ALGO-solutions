#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int n, base = 1;
	cin >> n;
	while (base <= n) base *= 2;
	vector<int> a(n), h(n);
	for (int& x : h) cin >> x;
	for (int& x : a) cin >> x;
	vector<ll> dp(n + 1); // dp[i] is the maximum value choosing the flower with height h[i] 
	vector<ll> tree(2 * base); // segment tree for range maximum
	for (int flower = 0; flower < n; ++flower)
	{
		int x = h[flower] + base;
		ll res = 0;
		while (x) // range query in [0,h[flower]-1]
		{
			if (x & 1) res = max(res, tree[x - 1]);
			x /= 2;
		}
		dp[h[flower]] = res + a[flower];
		for (int i = h[flower] + base; i >= 1; i /= 2) // update in tree
			tree[i] = max(tree[i], dp[h[flower]]);
	}
	ll res = *max_element(dp.begin(), dp.end()); // result will be the maximum value of dp array
	cout << res << "\n";
	return 0;
}