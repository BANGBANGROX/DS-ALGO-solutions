// https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
		int n = tops.size();
		int ans = INT_MAX;

		for (int value = 1; value < 7; ++value) {
			int topCost = 0;
			int bottomCost = 0;
			bool found = true;
			for (int i = 0; i < n; ++i) {
				if (tops[i] != value && bottoms[i] != value) {
					found = false;
					break;
				}
				if (tops[i] != value) ++topCost;
				if (bottoms[i] != value) ++bottomCost;
			}
			if (found) ans = min({ ans,topCost,bottomCost });
		}

		return ans == INT_MAX ? -1 : ans;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		vector<int> tops(n);
		for (int& x : tops) cin >> x;
		vector<int> bottoms(n);
		for (int& x : bottoms) cin >> x;

		Solution solution;
		cout << solution.minDominoRotations(tops, bottoms) << endl;
	}

	return 0;
}