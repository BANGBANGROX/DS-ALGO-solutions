#include<bits/stdc++.h>
using namespace std;

class Solution {
	vector<vector<int>> dp;

	int findNextEvent(vector<vector<int>>& events, int endTime) {
		int l = 0;
		int r = events.size() - 1;
		int ans = events.size();

		while (l <= r) {
			int mid = (l + ((r - l) >> 1));
			if (events[mid][0] > endTime) {
				ans = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}

		return ans;
	}

	int maxValueUtil(vector<vector<int>>& events, int index, int eventsLeft) {
		if (index == events.size() || eventsLeft == 0) return 0;

		if (dp[index][eventsLeft] != -1) return dp[index][eventsLeft];

		// Lets leave the current event
		int ans = maxValueUtil(events, index + 1, eventsLeft);

		// Now we take the current event
		int nextEvent = findNextEvent(events, events[index][1]);
		ans = max(ans, events[index][2] + maxValueUtil(events, nextEvent, eventsLeft - 1));

		return dp[index][eventsLeft] = ans;
	}

public:
	int maxValue(vector<vector<int>>& events, int k) {
		sort(events.begin(), events.end());

		dp = vector<vector<int>>(events.size(), vector<int>(k + 1, -1));

		return maxValueUtil(events, 0, k);
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n, k;
		cin >> n;
		vector<vector<int>> events(n, vector<int>(3));
		for (int i = 0; i < n; ++i) {
			cin >> events[i][0] >> events[i][1] >> events[i][2];
		}
		cin >> k;

		Solution solution;
		cout << solution.maxValue(events, k) << endl;
	}

	return 0;
}