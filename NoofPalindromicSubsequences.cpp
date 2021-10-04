#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;

ll countPS(string s) {
	int n = s.size();
	vector<vector<ll>> dp(n + 1, vector<ll>(n + 1)); // dp[i][j] is the no of PS from i to j
	for (int i = 0; i < n; ++i) {
		dp[i][i] = 1;
	}

	for (int len = 2; len <= n; ++len) {
		for (int i = 0; i <= n - len; ++i) {
			int j = i + len - 1;
			if (s[i] == s[j]) { // if s[i] == s[j] then we can add it to seq i+1...j and also to i...j-1
				dp[i][j] = (dp[i + 1][j] + dp[i][j - 1] + 1) % mod;
			}
			else { // else for i...j we can have i+1...j and i...j-1 but here we included i+1...j-1 twice so subtract it
				dp[i][j] = (dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1] + mod) % mod;
			}
		}
	}

	return dp[0][n - 1];
}

int main() {
	string s;
	cin >> s;
	cout << countPS(s) << endl;

	return 0;
}