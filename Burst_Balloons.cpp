#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int maxCoins(vector<int>& nums) {
		int n = nums.size() + 2;
		vector<vector<int>> dp(n, vector<int>(n));
		vector<int> newNums(n, 1);
		int i = 1;

		for (int num : nums) {
			newNums[i] = num;
			++i;
		}

		for (int len = 1; len <= n; ++len) {
			for (int i = 0; i <= n - len; ++i) {
				int j = len + i - 1;
				for (int k = i + 1; k < j; ++k) {
					dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + newNums[i] * newNums[k] * newNums[j]);
				}
			}
		}

		return dp[0][n - 1];
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		vector<int> nums(n);
		for (int& x : nums) cin >> x;

		Solution obj;
		cout << obj.maxCoins(nums) << endl;
	}

	return 0;
}