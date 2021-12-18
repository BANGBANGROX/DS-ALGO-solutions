// { Driver Code Starts
#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;
typedef long long int ll;


// } Driver Code Ends

class Solution {
public:
	//Function to count subarrays with 1s and 0s.
	ll countSubarrWithEqualZeroAndOne(int arr[], int n) {
		//Your code here
		unordered_map<int, ll> cnt;
		ll currSum = 0, res = 0;

		for (int i = 0; i < n; ++i) {
			currSum += (arr[i] == 0) ? -1LL : 1LL;
			if (currSum == 0) {
				++res;
			}
			res += cnt[-1 * currSum];
			++cnt[-1 * currSum];
		}

		return res;
	}
};

// { Driver Code Starts.

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, i;
		cin >> n;
		int* arr = new int[n];
		for (i = 0; i < n; i++)
			cin >> arr[i];
		Solution obj;
		cout << obj.countSubarrWithEqualZeroAndOne(arr, n) << "\n";
	}
	return 0;
}
// } Driver Code Ends