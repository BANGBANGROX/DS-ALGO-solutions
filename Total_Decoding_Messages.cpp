//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	string s;
	int n;
	vector<int> dp;
	const int mod = 1e9 + 7;

	int countWaysUtil(int index) {
		if (index == n) return 1;

		if (dp[index] != -1) return dp[index];

		int ans = 0;

		// Take the current character
		ans = (ans + countWaysUtil(index + 1)) % mod;

		// If possible take the next character
		if (index + 1 < n) {
			if (s[index] == '1' || (s[index] == '2' && s[index + 1] <= '6')) {
				ans = (ans + countWaysUtil(index + 2)) % mod;
			}
		}

		return dp[index] = ans;
	}

public:
	int CountWays(string s) {
		// Code here
		this->s = s;
		n = s.size();
		dp = vector<int>(n, -1);

		return countWaysUtil(0);
	}

};

//{ Driver Code Starts.
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends