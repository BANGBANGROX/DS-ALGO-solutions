#include<bits/stdc++.h>
using namespace std;

int maximumAmount(vector<int>& a, int n) {
	vector<vector<int>> dp(n, vector<int>(n)); 
	// dp[i][j] is the maximum profit player 1 can achieve in [i...j]

	for (int gap = 0; gap < n; ++gap) {  // we consider intervals [i...gap] [i...gap+1] and so on
		for (int i = 0, j = gap; j < n; ++i, ++j) {
			int x = 0, y = 0, z = 0;
			if (i + 2 <= j) x = dp[i + 2][j]; // if we pick i and opponent picks i then we have [i+2...j] to consider
			if (i + 1 < j - 1) y = dp[i + 1][j - 1]; // we pick i(or j) and he picks j(or i) then [i+1...j-1]
			if (i < j - 2) z = dp[i][j - 2]; // we pick j and he picks j then [i...j-2]
			dp[i][j] = max(a[i] + min(x, y), a[j] + min(y, z));
		}
	}

	return dp[0][n - 1];
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& x : a) cin >> x;
	cout << maximumAmount(a, n) << endl;
	return 0;
}
