// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	int buyMaximumProducts(int n, int k, int price[]) {
		//Write your code here
		int ans = 0;
		vector<pair<int, int>> priceWithDays;

		for (int i = 0; i < n; ++i) {
			priceWithDays.push_back({ price[i],i + 1 });
		}

		sort(priceWithDays.begin(), priceWithDays.end());

		for (pair<int, int>& x : priceWithDays) {
			if (x.first * x.second <= k) {
				ans += x.second;
				k -= x.first * x.second;
			}
			else {
				ans += (k / x.first);
				break;
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
		int n, k;
		cin >> n >> k;
		int* price = new int[n];
		for (int i = 0; i < n; i++) {
			cin >> price[i];
		}
		Solution ob;
		int ans = ob.buyMaximumProducts(n, k, price);
		cout << ans << endl;
	}
	return 0;
}
// } Driver Code Ends