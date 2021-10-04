#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> values(n);
	for (int& x : values) cin >> x;
	vector<bool> dp(k + 1); // dp[i] is true if the player making the move can win with i stones remaining else it is false
	for (int stones = 0; stones <= k; ++stones)
	{
		for (int x : values)
		{
			if (stones >= x)
			{
				if (!dp[stones - x]) dp[stones] = 1; // stones - x is a losing position so stones becomes the winning position for the player making the move
			}
		}
	}
	if (dp[k]) cout << "First\n";
	else cout << "Second\n";
	return 0;
}
