// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// ranges[i][0] is the start of ith range
// ranges[i][1] is the end of ith range

class Solution {
	static bool comp(const vector<int>& range1, const vector<int>& range2) {
		return range1[1] != range2[1] ? range1[1] < range2[1] : range1[0] < range2[0];
	}

public:
	int max_non_overlapping(vector< vector<int> >& ranges) {
		// code here
		int ans = 1;
		int n = ranges.size();

		sort(ranges.begin(), ranges.end(), comp);

		int last = ranges[0][1];

		for (int i = 1; i < n; ++i) {
			if (ranges[i][0] >= last) {
				++ans;
				last = ranges[i][1];
			}
		}

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

		vector< vector<int> > v(n, vector<int>(2));
		for (int i = 0; i < n; i++)
			cin >> v[i][0] >> v[i][1];

		Solution ob;
		cout << ob.max_non_overlapping(v) << endl;
	}
	return 1;
}

// } Driver Code Ends