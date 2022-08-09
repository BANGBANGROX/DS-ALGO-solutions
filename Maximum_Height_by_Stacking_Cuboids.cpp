#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int maxHeight(vector<vector<int>>& cuboids) {
		int n = cuboids.size();
		int ans = 0;
		vector<int> dp(n);

		for (int i = 0; i < n; ++i) {
			sort(cuboids[i].begin(), cuboids[i].end());
		}

		sort(cuboids.begin(), cuboids.end(), [](vector<int>& a, vector<int>& b) {
			if (a[0] != b[0]) return a[0] > b[0];

			if (a[1] != b[1]) return a[1] > b[1];

			return a[2] > b[2];
			});

		for (int i = 0; i < n; ++i) {
			int maxValue = 0;
			for (int j = 0; j < i; ++j) {
				if (cuboids[i][0] <= cuboids[j][0] && cuboids[i][1] <= cuboids[j][1] && 
					cuboids[i][2] <= cuboids[j][2]) {
					maxValue = max(maxValue, dp[j]);
				}
			}
			dp[i] = maxValue + cuboids[i][2];
			ans = max(ans, dp[i]);
		}

		return ans;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		vector<vector<int>> cuboids(n, vector<int>(3));
		for (int i = 0; i < n; ++i) {
			cin >> cuboids[i][0] >> cuboids[i][1] >> cuboids[i][2];
		}

		Solution solution;
		cout << solution.maxHeight(cuboids) << endl;
	}

	return 0;
}