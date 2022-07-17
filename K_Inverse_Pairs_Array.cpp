#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int kInversePairs(int n, int k) {
		if (k == 0) return 1;

		vector<vector<int>> dp(n + 1, vector<int>(k + 1));
		const int mod = 1e9 + 7;

		for (int i = 1; i <= n; ++i) {
			dp[i][0] = 1;
			for (int j = 1; j <= k; ++j) {
				int res = (dp[i - 1][j] - (j >= i ? dp[i - 1][j - i] : 0) + mod) % mod;
				dp[i][j] = (dp[i][j - 1] + res) % mod;
			}
		}

		return (dp[n][k] - dp[n][k - 1] + mod) % mod;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n, k;
		cin >> n >> k;

		Solution solution;
		cout << solution.kInversePairs(n, k) << endl;
	}

	return 0;
}