// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    typedef long long int ll;
	const int mod = 1e9 + 7;

	void multiply(ll a[2][2], ll b[2][2]) {
		ll x = ((a[0][0] * b[0][0]) % mod + (a[0][1] * b[1][0]) % mod) % mod;
		ll y = ((a[0][0] * b[0][1]) % mod + (a[0][1] * b[1][1]) % mod) % mod;
		ll z = ((a[1][0] * b[0][0]) % mod + (a[1][1] * b[1][0]) % mod) % mod;
		ll w = ((a[1][0] * b[0][1]) % mod + (a[1][1] * b[1][1]) % mod) % mod;

		a[0][0] = x;
		a[0][1] = y;
		a[1][0] = z;
		a[1][1] = w;
	}

	int TotalAnimal(ll n) {
		// Code here

		if (n == 1) return 1;

		if (n == 2) return 2;

		ll ide[2][2] = { {1,0},{0,1} };
		ll fib[2][2] = { {0,1},{1,1} };

		n -= 2;

		while (n) {
			if (n % 2 == 1) {
				multiply(ide, fib);
				--n;
			}
			multiply(fib, fib);
			n /= 2;
		}

		ll ans = (ide[0][1] + 2 * ide[1][1]) % mod;

		return ans;
	}
};

// { Driver Code Starts.
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		long long int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalAnimal(N);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends