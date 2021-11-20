#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

int maxTwoEvents(vector<vector<int>>& events) {
	int n = events.size(), ans = 0, maxValue = 0;
	map<int, int> dp;

	sort(events.begin(), events.end());

	for (int i = n - 1; i > -1; --i) {
		auto it = dp.upper_bound(events[i][1]);
		maxValue = max(maxValue, events[i][2]);
		dp[events[i][0]] = maxValue;
		if (it == dp.end()) ans = max(ans, maxValue);
		else ans = max(ans, events[i][2] + it->second);
	}

	return ans;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;

		vector<vector<int>> events;

		for (int i = 0; i < n; ++i) {
			int a, b, c;
			cin >> a >> b >> c;
			events.push_back({ a,b,c });
		}

		cout << maxTwoEvents(events) << endl;
	}

	return 0;
}