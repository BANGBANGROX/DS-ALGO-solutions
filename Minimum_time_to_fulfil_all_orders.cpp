// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
	bool check(vector<int>& ratings, int maxTime, int target) {
		int total = 0;

		for (int r : ratings) {
			int c = maxTime * 2 / r;
			int donuts = (-1 + (int)sqrt(1 + 4 * c)) / 2;
			total += donuts;
			if (total >= target) return true;
		}

		return false;
	}

public:
	int findMinTime(int target, vector<int>& ratings, int L) {
		//write your code here
		int l = 1;
		int r = 1e9;
		int ans = -1;

		while (l <= r) {
			int mid = (l + ((r - l) >> 1));
			if (check(ratings, mid, target)) {
				ans = mid;
				r = mid - 1;
			}
			else l = mid + 1;
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
		int l;
		cin >> l;
		vector<int>arr(l);
		for (int i = 0; i < l; i++) {
			cin >> arr[i];
		}
		Solution ob;
		int ans = ob.findMinTime(n, arr, l);
		cout << ans << endl;
	}
	return 0;
}
// } Driver Code Ends