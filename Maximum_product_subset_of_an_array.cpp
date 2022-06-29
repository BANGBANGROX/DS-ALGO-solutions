// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
	typedef long long int ll;
public:
	ll findMaxProduct(vector<int>& a, int n) {
		//Write your code here
		ll ans = 1;
		ll zeroesCount = 0;
		ll negativeCount = 0;
		ll maxNeg = INT_MIN;
		const int mod = 1e9 + 7;

		if (n == 1) return a[0];

		for (int i = 0; i < n; ++i) {
			if (a[i] == 0) {
				++zeroesCount;
				continue;
			}
			if (a[i] < 0) {
				++negativeCount;
				maxNeg = max(maxNeg, (ll)a[i]);
			}
			ans = (ans * a[i]) % mod;
		}

		if (zeroesCount == n) return 0;

		if ((negativeCount & 1) > 0) {
			if (negativeCount == 1 && (zeroesCount + negativeCount == n)) return 0;
			ans /= maxNeg;
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
		vector<int>arr(n);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		Solution ob;
		long long int ans = ob.findMaxProduct(arr, n);
		cout << ans << endl;
	}
	return 0;
}
// } Driver Code Ends