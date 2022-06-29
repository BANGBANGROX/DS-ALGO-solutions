// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
	typedef long long ll;
public:
	//Function to count the number of ways in which frog can reach the top.
	ll countWays(int n) {
		// your code here
		if (n == 1) return 1;

		if (n == 2) return 2;

		if (n == 3) return 4;

		vector<ll> dp(n + 1);
		const int mod = 1e9 + 7;

		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 4;

		for (int i = 4; i <= n; ++i) {
			dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % mod;
		}

		return dp[n];
	}
};


// { Driver Code Starts.
int main()
{
	//taking testcases
	int t;
	cin >> t;

	while (t--)
	{
		//taking number of steps in stair
		int n;
		cin >> n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}

	return 0;

}
// } Driver Code Ends