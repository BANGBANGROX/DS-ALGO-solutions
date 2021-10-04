#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
	int n = intervals.size();
	vector<vector<int>> res;

	sort(intervals.begin(), intervals.end());

	res.push_back(intervals[0]);

	for (int i = 1; i < n; ++i) {
		if (intervals[i][0] <= res.back()[1]) {
			vector<int> temp = res.back();
			res.pop_back();
			res.push_back({ temp[0], max(temp[1], intervals[i][1]) });
		}
		else {
			res.push_back(intervals[i]);
		}
	}

	return res;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<vector<int>> intervals(n, vector<int>(2));

		for (int i = 0; i < n; ++i) {
			int a, b;
			cin >> a >> b;
			intervals[i] = { a,b };
		}

		vector<vector<int>> res = merge(intervals);

		for (vector<int> x : res) {
			for (int y : x) cout << y << " ";
			cout << endl;
		}
	}

	return 0;
}
