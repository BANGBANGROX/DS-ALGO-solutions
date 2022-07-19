//{ Driver Code Starts
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;


// } Driver Code Ends

class Solution {
public:
	int lenOfLongSubarr(int nums[], int n, int target) {
		// Complete the function
		unordered_map<int, int> indexOfSum;
		int sum = 0;
		int maxLen = 0;

		for (int i = 0; i < n; ++i) {
			sum += nums[i];
			if (sum == target) maxLen = i + 1;
			if (indexOfSum.find(sum - target) != indexOfSum.end()) {
				maxLen = max(maxLen, i - indexOfSum[sum - target]);
			}
			if (indexOfSum.find(sum) == indexOfSum.end()) indexOfSum[sum] = i;
		}

		return maxLen;
	}

};

//{ Driver Code Starts.

int main() {
	//code

	int t; cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		int* a = new int[n];

		for (int i = 0; i < n; i++)
			cin >> a[i];
		Solution ob;
		cout << ob.lenOfLongSubarr(a, n, k) << endl;

	}

	return 0;
}
// } Driver Code Ends