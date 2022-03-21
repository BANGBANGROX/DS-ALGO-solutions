#include<bits/stdc++.h>
using namespace std;

class Solution {
	int maxScoreForBob(int idx, int numArrows, vector<vector<int>>& dp, vector<int>& aliceScores) {
		if (idx == 12 || numArrows == 0) return 0;

		if (dp[idx][numArrows] != -1) return dp[idx][numArrows];

		int maxScore = maxScoreForBob(idx + 1, numArrows, dp, aliceScores);

		if (numArrows > aliceScores[idx]) {
			maxScore = max(maxScore, 
				maxScoreForBob(idx + 1, numArrows - aliceScores[idx] - 1, dp, aliceScores) + idx);
		}

		return dp[idx][numArrows] = maxScore;
	}

public:
	vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
		vector<vector<int>> dp(13, vector<int>(numArrows + 1, -1));
		vector<int> ans(12);
		int remainingArrows = numArrows;

		for (int i = 0; i < 12; ++i) {
			if (maxScoreForBob(i, numArrows, dp, aliceArrows) !=
				maxScoreForBob(i + 1, numArrows, dp, aliceArrows)) {
				ans[i] = aliceArrows[i] + 1;
				numArrows -= ans[i];
				remainingArrows -= ans[i];
			}
		}

		ans[0] += remainingArrows;

		return ans;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int numArrows;
		cin >> numArrows;
		vector<int> aliceArrows(12);
		for (int& x : aliceArrows) cin >> x;

		Solution solution;
		vector<int> ans = solution.maximumBobPoints(numArrows, aliceArrows);
		for (int& x : ans) cout << x << " ";
		cout << endl;
	}

	return 0;
}