// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
public:
	int overlap(vector<pair<int, int>>& intervals, int n) {
		//Write your code here
		vector<int> start(n);
		vector<int> end(n);

		for (int i = 0; i < n; ++i) {
			start[i] = intervals[i].first;
			end[i] = intervals[i].second;
		}

		sort(start.begin(), start.end());
		sort(end.begin(), end.end());

		int i = 1;
		int j = 0;
		int ans = 1;
		int currentIntervals = 1;

		while (i < n && j < n) {
			if (start[i] <= end[j]) {
				++currentIntervals;
				++i;
			}
			else {
				ans = max(ans, currentIntervals);
				--currentIntervals;
				++j;
			}
		}

		ans = max(ans, currentIntervals);

		return ans;
	}
};



// { Driver Code Starts.
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<pair<int, int>>intervals;
		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			intervals.push_back({ a, b });
		}
		Solution ob;
		int ans = ob.overlap(intervals, n);
		cout << ans << endl;
	}
	return 0;
}
// } Driver Code Ends