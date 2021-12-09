// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	
	typedef long long ll;

	const int mod = 1e9 + 7;

	ll binExp(int a, int b) {
		ll res = 1;

		while (b) {
			if (b & 1) {
				res = ((res % mod) * ((ll)a % mod)) % mod;
				--b;
			}
			a = (((ll)a % mod) * (a % mod)) % mod;
			b /= 2;
		}

		return res;
	}

	int totalWays(int n, int k) {
		// Code here.
		if (n < k) return 0;

		if (n == k) return 1;

		--n;
		--k;

		vector<ll> fact(n + 1);

		fact[0] = 1;

		for (int i = 1; i <= n; ++i) 
			fact[i] = (fact[i - 1] * (ll)i) % mod;

		ll val1 = fact[n], val2 = binExp(fact[n - k], mod - 2), val3 = binExp(fact[k], mod - 2);
		ll ans = ((val1 * val2) % mod * val3) % mod;

		return ans;
	}
};

// { Driver Code Starts.
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int n, k;
		cin >> n >> k;
		Solution ob;
		int ans = ob.totalWays(n, k);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
