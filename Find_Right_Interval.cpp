#include<bits/stdc++.h>
using namespace std;

class Solution {
	int lowerBound(vector<vector<int>>& intervals, int key) {
		int n = intervals.size();
		int l = 0;
		int r = n - 1;
		int ans = -1;

		while (l <= r) {
			int mid = (l + ((r - l) >> 1));
			if (intervals[mid][0] >= key) {
				ans = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}

		return ans;
	}

public:
	vector<int> findRightInterval(vector<vector<int>>& intervals) {
		int n = intervals.size();
		vector<vector<int>> sortedIntervals;
		vector<int> ans(n);
		
		for (int i = 0; i < n; ++i) {
			sortedIntervals.push_back({ intervals[i][0],intervals[i][1],i });
		}

		sort(sortedIntervals.begin(), sortedIntervals.end());

		for (int i = 0; i < n; ++i) {
			int idx = lowerBound(sortedIntervals, sortedIntervals[i][1]);
			if (idx == -1) {
				ans[sortedIntervals[i][2]] = -1;
			}
			else {
				ans[sortedIntervals[i][2]] = sortedIntervals[idx][2];
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
		for (vector<int>& interval : intervals) {
			cin >> interval[0] >> interval[1];
		}

		Solution solution;
		vector<int> ans = solution.findRightInterval(intervals);
		for (int& x : ans) cout << x << " ";
		cout << endl;
	}

	return 0;
}