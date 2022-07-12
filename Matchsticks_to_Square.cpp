#include<bits/stdc++.h>
using namespace std;

class Solution {
	bool makeSquareUtil(vector<int>& matchsticks, int k, int currentSum, int subsetSum, 
		vector<bool>& visited, int index) {
		if (k == 1) return true;

		if (currentSum == subsetSum) {
			return makeSquareUtil(matchsticks, k - 1, 0, subsetSum, visited, 0);
		}

		int n = visited.size();

		for (int i = index; i < n; ++i) {
			if (visited[i] || currentSum + matchsticks[i] > subsetSum) continue;
			currentSum += matchsticks[i];
			visited[i] = true;
			if (makeSquareUtil(matchsticks, k, currentSum, subsetSum, visited, i + 1)) return true;
			currentSum -= matchsticks[i];
			visited[i] = false;
		}

		return false;
	}

public:
	bool makesquare(vector<int>& matchsticks) {
		int n = matchsticks.size();
		int totalSum = accumulate(matchsticks.begin(), matchsticks.end(), 0);

		if (totalSum % 4 != 0) return false;

		int subsetSum = totalSum / 4;
		int index = 0;
		int currentSum = matchsticks[index];
		vector<bool> visited(n);

		visited[index] = true;

		return makeSquareUtil(matchsticks, 4, currentSum, subsetSum, visited, index);
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		vector<int> matchsticks(n);
		for (int& x : matchsticks) cin >> x;

		Solution solution;
		cout << solution.makesquare(matchsticks);
	}

	return 0;
}