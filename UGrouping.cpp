#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> pre, dp;
void rec(int pos, const vector<int>& not_taken, ll score_so_far, int mask, int groups)
{
	if (pos == (int)not_taken.size())
	{
		dp[mask] = max(dp[mask], score_so_far + pre[groups]);
		return;
	}
	rec(pos + 1, not_taken, score_so_far, mask, groups);
	rec(pos + 1, not_taken, score_so_far, mask ^ (1 << not_taken[pos]), groups ^ (1 << not_taken[pos]));
}
int main()
{
	int n;
	cin >> n;
	vector<vector<ll>> can(n, vector<ll>(n));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			cin >> can[i][j];
	}
	dp.resize((1 << n));
	pre.resize((1 << n));
	for (int mask = 0; mask < (1 << n); ++mask)
	{
		for (int i = 0; i < n; ++i)
		{
			if (mask & (1 << i))
			{
				for (int j = i + 1; j < n; ++j)
				{
					if (mask & (1 << j))
						pre[mask] += can[i][j];
				}
			}
		}
	}
	dp[0] = 0;
	for (int mask = 0; mask < (1 << n); ++mask)
	{
		vector<int> not_taken;
		for (int i = 0; i < n; ++i)
		{
			if (!(mask & (1 << i))) not_taken.push_back(i);
		}
		rec(0, not_taken, dp[mask], mask, 0);
	}
	ll res = dp[(1 << n) - 1];
	cout << res << "\n";
	return 0;
}