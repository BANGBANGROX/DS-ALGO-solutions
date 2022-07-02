// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	typedef long long int ll;

	const int mod = 1e9 + 7;

	void multiply(vector<vector<ll>>& a, vector<vector<ll>>& b) {
		ll w = ((a[0][0] * b[0][0]) % mod + (a[0][1] * b[1][0]) % mod) % mod;
		ll x = ((a[0][0] * b[0][1]) % mod + (a[0][1] * b[1][1]) % mod) % mod;
		ll y = ((a[1][0] * b[0][0]) % mod + (a[1][1] * b[1][0]) % mod) % mod;
		ll z = ((a[1][0] * b[0][1]) % mod + (a[1][1] * b[1][1]) % mod) % mod;

		a[0][0] = w;
		a[0][1] = x;
		a[1][0] = y;
		a[1][1] = z;
	}

	vector<vector<ll>> binExponentiationOnMatrix(ll n) {
		vector<vector<ll>> res = { {1, 0}, {0, 1} };
		vector<vector<ll>> a = { {0, 1}, {1, 1} };

		while (n > 0) {
			if ((n & 1) > 0) {
				multiply(res, a);
				--n;
			}
			multiply(a, a);
			n >>= 1;
		}

		return res;
	}

public:
	int FindNthTerm(ll n) {
		// Code here
		if (n < 2) return 1;

		vector<vector<ll>> ans = binExponentiationOnMatrix(n - 1);

		return (ans[1][0] + ans[1][1]) % mod;
	}
};

// { Driver Code Starts.
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		long long int n;
		cin >> n;
		Solution obj;
		int ans = obj.FindNthTerm(n);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends