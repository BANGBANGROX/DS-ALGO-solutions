#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minimumFinishTime(vector<vector<int>>& tires, int changeTime, int numLaps) {
		vector<int> initialTime(19, INT_MAX);
		vector<int> dp(numLaps + 1);
		int maxTime = pow(2, 17);

		for (const vector<int>& tire : tires) {
			int f = tire[0];
			int r = tire[1];
			int totalTimeTaken = 0;
			for (int i = 1; i <= numLaps; ++i) {
				if (f >= maxTime / (int)pow(r, i - 1)) break;
				int currentLapTime = f * (int)pow(r, i - 1);
				totalTimeTaken += currentLapTime;
				if (totalTimeTaken > maxTime) break;
				initialTime[i] = min(initialTime[i], totalTimeTaken);
			}
		}

		for (int i = 1; i <= numLaps; ++i) {
			dp[i] = (i < 19) ? initialTime[i] : INT_MAX;
			for (int j = 1; j < i; ++j) {
				dp[i] = min(dp[i], changeTime + dp[i - j] + dp[j]);
			}
		}

		return dp[numLaps];
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n, changeTime, numLaps;
		cin >> n;
		vector<vector<int>> tires(n, vector<int>(2));
		for (int i = 0; i < n; ++i) {
			cin >> tires[i][0] >> tires[i][1];
		}
		cin >> changeTime >> numLaps;

		Solution solution;
		cout << solution.minimumFinishTime(tires, changeTime, numLaps) << endl;
	}

	return 0;
}