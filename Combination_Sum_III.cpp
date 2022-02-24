#include<bits/stdc++.h>
using namespace std;

class Solution {
	vector<vector<int>> ans;
	vector<int> currentCombination;

	void combinationSum3Util(int k, int n, int num) {
		if (n == 0 && k == 0) {
			ans.push_back(currentCombination);
			return;
		}

		if (k == 0 || num > 9 || num > n) return;

		// Let's take the number
		currentCombination.push_back(num);
		combinationSum3Util(k - 1, n - num, num + 1);
		currentCombination.pop_back();

		// Let's leave the number
		combinationSum3Util(k, n, num + 1);
	}

public:
	vector<vector<int>> combinationSum3(int k, int n) {
		combinationSum3Util(k, n, 1);

		return ans;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int k, n;
		cin >> k >> n;

		Solution solution;
		vector<vector<int>> ans = solution.combinationSum3(k, n);
		for (const vector<int>& x : ans) {
			for (const int& y : x) cout << y << " ";
			cout << endl;
		}
	}

	return 0;
}