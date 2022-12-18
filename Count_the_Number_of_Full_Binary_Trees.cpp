//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	typedef long long int ll;
public:
	ll numoffbt(ll nums[], int n) {
		// Your code goes here
		const int MOD = (int)1e9 + 7;
		int maxValue = *max_element(nums, nums + n);
		int minValue = *min_element(nums, nums + n);
		ll ans = 0;
		vector<bool> present(maxValue + 1);
		vector<ll> dp(maxValue + 1);

		for (int i = 0; i < n; ++i) {
			present[nums[i]] = true;
			dp[nums[i]] = 1;
		}

		for (int i = minValue; i <= maxValue; ++i) {
			if (!present[i]) continue;
			for (int j = 2; i * j <= maxValue && j <= i; ++j) {
				int parent = i * j;
				if (!present[parent]) continue;
				dp[parent] = (dp[parent] + (dp[i] * dp[j]) % MOD) % MOD;
				if (i != j) {
					dp[parent] = (dp[parent] + (dp[i] * dp[j]) % MOD) % MOD;
				}
			}
			ans = (ans + dp[i]) % MOD;
		}

		return ans;
	}
};


//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		long long int* a = new long long int[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		Solution ob;
		cout << ob.numoffbt(a, n) << endl;

	}
	return 0;
}


// } Driver Code Ends