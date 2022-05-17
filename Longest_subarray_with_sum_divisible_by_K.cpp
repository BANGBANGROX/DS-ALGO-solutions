// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution {
public:
	int longSubarrWthSumDivByK(int nums[], int n, int k) {
		// Complete the function
		vector<int> prefixSum(n);
		vector<int> firstIndex(k, -1);
		vector<int> lastIndex(k, -1);
		int ans = 0;

		prefixSum[0] = ((nums[0] % k) + k) % k;
		lastIndex[prefixSum[0]] = firstIndex[prefixSum[0]] = 0;

		for (int i = 1; i < n; ++i) {
			prefixSum[i] = ((nums[i] + prefixSum[i - 1]) % k + k) % k;
			if (firstIndex[prefixSum[i]] == -1) firstIndex[prefixSum[i]] = i;
			lastIndex[prefixSum[i]] = i;
		}

		for (int i = 1; i < k; ++i) {
			ans = max(ans, lastIndex[i] - firstIndex[i]);
		}

		ans = max(ans, lastIndex[0] + 1);

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
		int n, k, i;
		cin >> n >> k; 
		int* arr = new int[n];
		for (i = 0; i < n; i++)
			cin >> arr[i];
		Solution ob;
		cout << ob.longSubarrWthSumDivByK(arr, n, k) << "\n";
	}
	return 0;
}
// } Driver Code Ends