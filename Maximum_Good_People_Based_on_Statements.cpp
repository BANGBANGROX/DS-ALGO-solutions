#include<bits/stdc++.h>
using namespace std;

class Solution {
	int countGoodPeople(int mask, vector<int>& currentState) {
		int n = currentState.size();
		int goodPeople = 0;

		for (int i = 0; i < n; ++i) {
			currentState[i] = mask & 1;
			if (currentState[i] == 1) ++goodPeople;
			mask >>= 1;
		}

		return goodPeople;
	}

	bool checkState(vector<vector<int>>& statements, vector<int>& currentState) {
		int n = currentState.size();

		for (int i = 0; i < n; ++i) {
			if (currentState[i] == 0) continue;
			for (int j = 0; j < n; ++j) {
				if (statements[i][j] == 2) continue;
				if (statements[i][j] != currentState[j]) return false;
			}
		}

		return true;
	}

public:
	int maximumGood(vector<vector<int>>& statements) {
		int maxGoodPeople = 0;
		int n = statements.size();

		for (int mask = 0; mask < (1 << n); ++mask) {
			vector<int> currentState(n);
			int currentGoodPeople = countGoodPeople(mask, currentState);
			if (checkState(statements, currentState)) {
				maxGoodPeople = max(maxGoodPeople, currentGoodPeople);
			}
		}

		return maxGoodPeople;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		vector<vector<int>> statements(n, vector<int>(n));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> statements[i][j];
			}
		}

		Solution solution;
		cout << solution.maximumGood(statements) << endl;
	}

	return 0;
}