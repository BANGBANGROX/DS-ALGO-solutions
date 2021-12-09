#include<bits/stdc++.h>
using namespace std;

static bool comp(const vector<int>& a, const vector<int>& b) {
	if (a[1] != b[1]) return a[0] < b[0];

	return a[0] < b[0];
}

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
	sort(intervals.begin(), intervals.end(), comp);

	int n = intervals.size(), ans = 0, maxEnd = INT_MIN;

	for (int i = 0; i < n; ++i) {
		if (intervals[i][0] >= maxEnd) {
			maxEnd = intervals[i][1];
			continue;
		}
		++ans;
	}

	return ans;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		vector<vector<int>> intervals(n);
		for (int i = 0; i < n; ++i) {
			int a, b;
			cin >> a >> b;
			intervals[i] = { a,b };
		}

		cout << eraseOverlapIntervals(intervals) << endl;
	}

	return 0;
}
