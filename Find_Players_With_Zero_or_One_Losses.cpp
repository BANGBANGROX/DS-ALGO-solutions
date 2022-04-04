#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

class Solution {
public:
	vector<vector<int>> findWinners(vector<vector<int>>& matches) {
		vector<vector<int>> ans(2);
		unordered_map<int, int> losses;
		unordered_map<int, int> wins;

		for (vector<int>& match : matches) {
			int u = match[0];
			int v = match[1];
			++losses[v];
			++wins[u];
		}

		for (const pair<int, int>& score : losses) {
			if (score.second == 1) ans[1].push_back(score.first);
		}

		for (const pair<int, int>& score : wins) {
			if (losses.find(score.first) == losses.end()) ans[0].push_back(score.first);
		}

		sort(ans[0].begin(), ans[0].end());
		sort(ans[1].begin(), ans[1].end());

		return ans;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		vector<vector<int>> matches(n, vector<int>(2));
		for (int i = 0; i < n; ++i) {
			cin >> matches[i][0] >> matches[i][1];
		}

		Solution solution;
		vector<vector<int>> ans = solution.findWinners(matches);
		for (int& x : ans[0]) cout << x << " ";
		cout << endl;
		for (int& x : ans[1]) cout << x << " ";
		cout << endl;
	}

	return 0;
} 