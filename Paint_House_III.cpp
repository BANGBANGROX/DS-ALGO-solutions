#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
		const int INF = 1e9;
		vector<vector<int>> dp(target + 1, vector<int>(n, INF));
		int ans = INF;

		if (houses[0] == 0) dp[1] = cost[0];
		else dp[1][houses[0] - 1] = 0;

		for (int i = 1; i < m; ++i) {
			for (int groups = target; groups > 0; --groups) {
				for (int color1 = 0; color1 < n; ++color1) {
					int minCost = dp[groups][color1];
					dp[groups][color1] = INF;
					if (houses[i] != 0 && houses[i] != color1 + 1) continue;
					int currentCost = (houses[i] == 0) ? cost[i][color1] : 0;
					minCost += currentCost;
					for (int color2 = 0; color2 < n; ++color2) {
						if (color1 == color2) continue;
						minCost = min(minCost, dp[groups - 1][color2] + currentCost);
					}
					dp[groups][color1] = minCost;
				}
			}
		}

		for (int i = 0; i < n; ++i) {
			ans = min(ans, dp[target][i]);
		}

		return ans < INF ? ans : -1;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int m;
		cin >> m;
		vector<int> houses(m);
		for (int& x : houses) cin >> x;
		int n;
		cin >> n;
		vector<vector<int>> cost(m, vector<int>(n));
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> cost[i][j];
			}
		}
		int target;
		cin >> target;

		Solution solution;
		cout << solution.minCost(houses, cost, m, n, target) << endl;
	}

	return 0;
}