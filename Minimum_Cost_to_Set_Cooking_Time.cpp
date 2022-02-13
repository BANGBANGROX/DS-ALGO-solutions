#include<bits/stdc++.h>
using namespace std;

class Solution {
	int minCostSetTimeUtil(int startAt, int moveCost, int pushCost, int minutes, int seconds) {
		int target = minutes * 100 + seconds;
		int ans = 0;
		vector<int> targetState;

		while (target > 0) {
			targetState.push_back(target % 10);
			target /= 10;
		}

		reverse(targetState.begin(), targetState.end());

		for (int i = 0; i < targetState.size(); ++i) {
			if (startAt == targetState[i]) {
				ans += pushCost;
				continue;
			}
			ans += (moveCost + pushCost);
			startAt = targetState[i];
		}

		return ans;
	}

public:
	int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
		int ans = INT_MAX;
		int minutes = targetSeconds / 60;
		int seconds = targetSeconds % 60;

		if (targetSeconds > 99) {
			if (minutes < 100) {
				ans = min(ans, minCostSetTimeUtil(startAt, moveCost, pushCost, minutes, seconds));
			}
			--minutes;
			seconds += 60;
			if (seconds < 100) {
				ans = min(ans, minCostSetTimeUtil(startAt, moveCost, pushCost, minutes, seconds));
			}
		}
		else {
			ans = min(ans, minCostSetTimeUtil(startAt, moveCost, pushCost, minutes, seconds));
			if (targetSeconds >= 60) {
				ans = min(ans, minCostSetTimeUtil(startAt, moveCost, pushCost, 0, targetSeconds));
			}
		}

		return ans;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int startAt, moveCost, pushCost, targetSeconds;
		cin >> startAt >> moveCost >> pushCost >> targetSeconds;

		Solution solution;
		cout << solution.minCostSetTime(startAt, moveCost, pushCost, targetSeconds) << endl;
	}

	return 0;
}