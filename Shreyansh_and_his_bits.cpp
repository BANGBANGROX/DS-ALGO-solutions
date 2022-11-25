//{ Driver Code Starts
//Initial Template for C++

#include <iostream>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
	typedef long long ll;

	ll nCr(int n, int r) {
		ll ans = 1;

		for (int i = 0; i < r; ++i) {
			ans *= ((ll)n - i);
			ans /= ((ll)i + 1);
		}

		return ans;
	}

public:
	ll count(ll n) {
		// Code Here
		ll ans = 0;
		int ones = 0;
		int pos = 0;

		while (n > 0) {
			if ((n & 1) > 0) {
				++ones;
				ans += nCr(pos, ones);
			}
			++pos;
			n >>= 1;
		}

		return ans;
	}
};

//{ Driver Code Starts.

int main() {

	int t;
	cin >> t;
	while (t-- > 0) {
		long long x; cin >> x;
		Solution ob;
		cout << ob.count(x) << '\n';
	}
	return 0;
}
// } Driver Code Ends