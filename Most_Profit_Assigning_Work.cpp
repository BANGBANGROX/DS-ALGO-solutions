#include<bits/stdc++.h>
using namespace std;

class Solution {
	int findMaxDifficultyJob(vector<pair<int, int>>& difficultyAndProfit, int key) {
		int n = difficultyAndProfit.size();
		int l = 0;
		int r = n - 1;
		int ans = -1;

		while (l <= r) {
			int mid = (l + ((r - l) >> 1));
			if (difficultyAndProfit[mid].first <= key) {
				ans = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}

		return ans;
	}

public:
	int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& workers) {
		int n = difficulty.size();
		int ans = 0;
		vector<pair<int, int>> difficultyAndProfit;
		vector<int> maxProfits(n);

		for (int i = 0; i < n; ++i) {
			difficultyAndProfit.push_back({ difficulty[i],profit[i] });
		}

		sort(difficultyAndProfit.begin(), difficultyAndProfit.end());

		maxProfits[0] = difficultyAndProfit[0].second;

		for (int i = 1; i < n; ++i) {
			maxProfits[i] = max(maxProfits[i - 1], difficultyAndProfit[i].second);
		}

		for (int worker : workers) {
			int idx = findMaxDifficultyJob(difficultyAndProfit, worker);
			if (idx == -1) continue;
			ans += maxProfits[idx];
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
		vector<int> difficulty(n), profit(n);
		for (int i = 0; i < n; ++i) {
			cin >> difficulty[i];
		}
		for (int i = 0; i < n; ++i) {
			cin >> profit[i];
		}
		int m;
		cin >> m;
		vector<int> workers(m);
		for (int i = 0; i < m; ++i) {
			cin >> workers[i];
		}

		Solution solution;
		cout << solution.maxProfitAssignment(difficulty, profit, workers) << endl;
	}

	return 0;
}