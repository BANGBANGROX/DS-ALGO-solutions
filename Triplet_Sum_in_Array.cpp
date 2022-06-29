// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
	//Function to find if there exists a triplet in the 
	//array A[] which sums up to X.
	bool find3Numbers(int nums[], int n, int target) {
		//Your Code Here
		sort(nums, nums + n);

		for (int i = 0; i < n - 2; ++i) {
			if (nums[i] > target) break;
			int newTarget = target - nums[i];
			int l = i + 1;
			int r = n - 1;
			while (l < r) {
				int sum = nums[l] + nums[r];
				if (sum == newTarget) return true;
				else if (sum > newTarget) --r;
				else ++l;
			}
		}

		return false;
	}
};

// { Driver Code Starts.

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n, X;
		cin >> n >> X;
		int i, * A = new int[n];
		for (i = 0; i < n; i++)
			cin >> A[i];
		Solution ob;
		cout << ob.find3Numbers(A, n, X) << endl;
	}
}
// } Driver Code Ends