// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
	bool check(vector<int>& heights, int target, int currentHeight) {
		int total = 0;

		for (int height : heights) {
			total += max(height - currentHeight, 0);
			if (total >= target) return true;
		}

		return false;
	}

public:
	int maxHeight(vector<int>& heights, int target) {
		//Write your code here
		int l = 1;
		int r = *max_element(heights.begin(), heights.end());
		int ans = -1;

		while (l <= r) {
			int mid = (l + ((r - l) >> 1));
			if (check(heights, target, mid)) {
				ans = mid;
				l = mid + 1;
			}
			else r = mid - 1;
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
		vector<int>A(n);
		for (int i = 0; i < n; i++) {
			cin >> A[i];
		}
		int M;
		cin >> M;
		Solution ob;
		int ans = ob.maxHeight(A, M);
		cout << ans << endl;
	}
	return 0;
}
// } Driver Code Ends