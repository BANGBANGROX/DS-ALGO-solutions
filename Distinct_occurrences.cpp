//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/

class Solution {
	vector<vector<int>> dp;
	string s;
	string t;
	int m;
	int n;
	const int mod = 1e9 + 7;

	int subsequenceCount(int i, int j) {
		if (i == m) return (j == n ? 1 : 0);

		if (j == n) return 1;

		if (dp[i][j] != -1) return dp[i][j];

		int ans = 0;

		ans = (ans + subsequenceCount(i + 1, j)) % mod;

		if (s[i] == t[j]) {
			ans = (ans + subsequenceCount(i + 1, j + 1)) % mod;
		}

		return dp[i][j] = ans;
	}

public:
	int subsequenceCount(string s, string t) {
		//Your code here
		this->s = s;
		this->t = t;
		m = s.size();
		n = t.size();
		dp = vector<vector<int>>(m, vector<int>(n, -1));
		
		return subsequenceCount(0, 0);
	}
};



//{ Driver Code Starts. 

//  Driver code to check above method
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		string tt;
		cin >> s;
		cin >> tt;

		Solution ob;
		cout << ob.subsequenceCount(s, tt) << endl;


	}

}
// } Driver Code Ends