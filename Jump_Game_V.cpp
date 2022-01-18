#include<bits/stdc++.h>
using namespace std;

class Solution {
	int maxJumpsUtil(int index, vector<int>& arr, int d, vector<int>& dp) {
		int maxCount = 1;
		int n = arr.size();

		if (dp[index] != -1) return dp[index];

		// Going right
		for (int i = index + 1; i <= min(n - 1, index + d) && arr[index] > arr[i]; ++i) {
			maxCount = max(maxCount, maxJumpsUtil(i, arr, d, dp) + 1);
		}

		// Going left
		for (int i = index - 1; i >= max(0, index - d) && arr[index] > arr[i]; --i) {
			maxCount = max(maxCount, maxJumpsUtil(i, arr, d, dp) + 1);
		}

		return dp[index] = maxCount;
	}

public:
	int maxJumps(vector<int>& arr, int d) {
		int n = arr.size();
		int maxCount = 1;
		vector<int> dp = vector<int>(n, -1);

		for (int i = 0; i < n; ++i) {
			if (dp[i] != -1) continue;
			maxCount = max(maxCount, maxJumpsUtil(i, arr, d, dp));
		}

		return maxCount;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n, d;
		cin >> n;
		vector<int> arr(n);
		for (int& x : arr) cin >> x;
		cin >> d;

		Solution solution;
		cout << solution.maxJumps(arr, d);
	}

	return 0;
}