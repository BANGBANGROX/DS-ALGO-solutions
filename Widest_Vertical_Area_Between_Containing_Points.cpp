#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int maxWidthOfVerticalArea(vector<vector<int>>& points) {
		int n = points.size();
		int ans = 0;

		sort(begin(points), end(points));

		for (int i = 1; i < n; ++i) {
			ans = max(ans, points[i][0] - points[i - 1][0]);
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
		vector<vector<int>> points(n, vector<int>(2));
		for (int i = 0; i < n; ++i) {
			cin >> points[i][0] >> points[i][1];
		}

		Solution solution;
		cout << solution.maxWidthOfVerticalArea(points) << endl;
	}

	return 0;
}