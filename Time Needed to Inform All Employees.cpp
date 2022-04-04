#include<bits/stdc++.h>
using namespace std;

class Solution {
	vector<vector<int>> tree;
	vector<int> timeOfCompletion; // timeOfCompletion[i] will indicate the time for completion of 
	                              // i and its descendants

	void dfs(int node, vector<int>&informTime) {
		int maxTime = 0;

		timeOfCompletion[node] += informTime[node];

		for (int child : tree[node]) {
			dfs(child, informTime);
			maxTime = max(maxTime, timeOfCompletion[child]); // dp
		}

		timeOfCompletion[node] += maxTime;
	}

public:
	int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
		tree = vector<vector<int>>(n);
		timeOfCompletion = vector<int>(n);

		for (int i = 0; i < n; ++i) {
			if (manager[i] == -1) continue;
			tree[manager[i]].push_back(i);
		}

		dfs(headID, informTime);

		return timeOfCompletion[headID];
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n, headID;
		cin >> n >> headID;
		vector<int> manager(n);
		for (int& x : manager) cin >> x;
		vector<int> informTime(n);
		for (int& x : informTime) cin >> x;

		Solution solution;
		cout << solution.numOfMinutes(n, headID, manager, informTime) << endl;
	}

	return 0;
}