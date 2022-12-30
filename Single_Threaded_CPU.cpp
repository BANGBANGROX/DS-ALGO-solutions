#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> getOrder(vector<vector<int>>& tasks) {
		int n = (int)tasks.size();
		vector<int> ans(n);
		vector<vector<int>> sortedTasks;
		priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

		for (int i = 0; i < n; ++i) {
			sortedTasks.push_back({ tasks[i][0],tasks[i][1],i });
		}

		sort(sortedTasks.begin(), sortedTasks.end());

		int taskIndex = 0;
		int ansIndex = 0;
		long long currentTime = 1;

		while (taskIndex < n || !pq.empty()) {
			if (pq.empty() && currentTime < sortedTasks[taskIndex][0]) {
				currentTime = sortedTasks[taskIndex][0];
			}
			while (taskIndex < n && currentTime >= sortedTasks[taskIndex][0]) {
				pq.push({ sortedTasks[taskIndex][1],
					sortedTasks[taskIndex][2], sortedTasks[taskIndex][0] });
				++taskIndex;
			}
			assert(!pq.empty());
			int processingTime = pq.top()[0];
			int index = pq.top()[1];
			pq.pop();
			currentTime += processingTime;
			ans[ansIndex] = index;
			++ansIndex;
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
		vector<vector<int>> tasks(n, vector<int>(2));
		for (vector<int>& x : tasks) {
			for (int& y : x) {
				cin >> y;
			}
		}

		Solution solution;
		vector<int> ans = solution.getOrder(tasks);
		for (int& x : ans) cout << x << " ";
		cout << endl;
	}

	return 0;
}