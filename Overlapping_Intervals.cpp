// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
		// Code here
		vector<vector<int>> ans;

		sort(intervals.begin(), intervals.end());
		ans.push_back(intervals[0]);

		int maxR = intervals[0][1];
		int n = intervals.size();

		for (int i = 1; i < n; ++i) {
			int l = intervals[i][0];
			int r = intervals[i][1];
			if (l > maxR) {
				ans.push_back(intervals[i]);
				maxR = r;
			}
			else {
				int prevL = ans.back()[0];
				maxR = max(maxR, r);
				ans.pop_back();
				ans.push_back({ prevL,maxR });
			}
		}

		return ans;
	}
};

// { Driver Code Starts.
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for (int i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for (auto i : ans) {
			for (auto j : i) {
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends