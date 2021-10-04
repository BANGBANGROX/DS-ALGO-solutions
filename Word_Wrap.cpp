#include<bits/stdc++.h>
using namespace std;

int solveWordWrap(vector<int>& nums, int k) {
	int n = nums.size();
	vector<vector<int>> lc(n + 1, vector<int>(n + 1)); // stores the cost of line from word i to word j
	vector<vector<int>> extra(n + 1, vector<int>(n + 1)); // stores the no of extra spaces for word i to word j
	vector<int> dp(n + 1, INT_MAX); // dp[i] stores ans for [1...i]
	for (int i = 1; i <= n; ++i) {
		extra[i][i] = k - nums[i - 1];
		for (int j = i + 1; j <= n; ++j) {
			extra[i][j] = extra[i][j - 1] - nums[j - 1] - 1;
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (extra[i][j] < 0) {
				lc[i][j] = INT_MAX;
			}
			else if (j == n) {
				lc[i][j] = 0;
			}
			else {
				lc[i][j] = extra[i][j] * extra[i][j];
			}
		}
	}
	dp[0] = 0;

	for (int j = 1; j <= n; ++j) {
		for (int i = 1; i <= j; ++i) {
			if (dp[i - 1] != INT_MAX && lc[i][j] != INT_MAX) { // consider [1...j] we can compute this as [1...i-1] + lc[i][j] to add the cost for arranging [i...j] 
				dp[j] = min(dp[i - 1] + lc[i][j], dp[j]);
			}
		}
	}

	return dp[n];
}

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int& x : a) cin >> x;

	cout << solveWordWrap(a, k) << endl;

	return 0;
}