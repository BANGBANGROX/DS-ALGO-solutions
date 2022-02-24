#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int removeCoveredIntervals(vector<vector<int>>& intervals) {
		int n = intervals.size();
		int ans = n;
		vector<bool> removed(n);

		for (int i = 0; i < n; ++i) {
			if (removed[i]) continue;
			int l1 = intervals[i][0];
			int r1 = intervals[i][1];
			for (int j = 0; j < n; ++j) {
				if (removed[j] || j == i) continue;
				int l2 = intervals[j][0];
				int r2 = intervals[j][1];
				if (l2 >= l1 && r2 <= r1) {
					--ans;
					removed[j] = true;
				}
			}
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
		vector<vector<int>> intervals(n, vector<int>(2));
		for (int i = 0; i < n; ++i) {
			cin >> intervals[i][0] >> intervals[i][1];
		}

		Solution solution;
		cout << solution.removeCoveredIntervals(intervals) << endl;
	}

	return 0;
}