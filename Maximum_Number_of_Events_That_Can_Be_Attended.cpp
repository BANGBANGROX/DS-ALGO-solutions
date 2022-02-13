#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

class Solution {
public:
	int maxEvents(vector<vector<int>>& events) {
		unordered_map<int, vector<int>> startDays;
		priority_queue<int, vector<int>, greater<int>> pq;
		int ans = 0;
		int firstDay = INT_MAX;
		int lastDay = INT_MIN;
		int n = events.size();

		for (int i = 0; i < n; ++i) {
			int start = events[i][0];
			int end = events[i][1];
			startDays[start].push_back(i);
			firstDay = min(firstDay, start);
			lastDay = max(lastDay, end);
		}

		for (int day = firstDay; day <= lastDay; ++day) {
			if (startDays.find(day) != startDays.end()) {
				for (int i : startDays[day]) {
					pq.push(events[i][1]);
				}
			}
			if (!pq.empty()) {
				++ans;
				pq.pop();
			}
			while (!pq.empty() && pq.top() == day) pq.pop();
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
		vector<vector<int>> events(n, vector<int>(2));
		for (int i = 0; i < n; ++i) {
			cin >> events[i][0] >> events[i][1];
		}

		Solution solution;
		cout << solution.maxEvents(events) << endl;
	}

	return 0;
}