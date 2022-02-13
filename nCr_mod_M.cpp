// { Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
	typedef long long ll;

    const ll mod = 1000003;
	vector<ll> fact;

	void computeFactorial() {
		fact = vector<ll>(mod + 1);

		fact[0] = 1;

		for (int i = 1; i <= mod; ++i) {
			fact[i] = ((fact[i - 1] % mod) * (ll)i) % mod;
		}
	}

	ll computePower(ll a, ll b) {
		ll res = 1;

		while (b > 0) {
			if ((b & 1) > 0) {
				res = ((res % mod) * (a % mod)) % mod;
				--b;
			}
			a = ((a % mod) * (a % mod)) % mod;
			b /= 2;
		}

		return res;
	}

	ll computeModularInverse(ll n) {
		return computePower(n, mod - 2);
	}

	ll NCR(ll n, ll r) {
		if (n < r) return 0;

		if (n == r) return 1;

		ll num = fact[n];
		ll den1 = computeModularInverse(fact[r]);
		ll den2 = computeModularInverse(fact[n - r]);
		ll denProduct = ((den1 % mod) * (den2 % mod)) % mod;
		ll ans = ((num % mod) * (denProduct % mod)) % mod;

		return ans;
	}

public:
	int nCr(long long n, long long r) {
		// Code here
		computeFactorial();

		ll p1 = mod;
		ll p2 = mod * mod;
		vector<ll> a1(3, 0);
		vector<ll> a2(3, 0);
		
		a1[2] = (n / p2);
		n %= p2;
		a1[1] = (n / p1);
		n %= p1;
		a1[0] = n;

		a2[2] = (r / p2);
		r %= p2;
		a2[1] = (r / p1);
		r %= p1;
		a2[0] = r;

		ll value1 = NCR(a1[0], a2[0]);
		ll value2 = NCR(a1[1], a2[1]);
		ll value3 = NCR(a1[2], a2[2]);
		ll product = ((value1 % mod) * (value2 % mod)) % mod;
		ll ans = ((value3 % mod) * (product % mod)) % mod;

		return ans;
	}
};

// { Driver Code Starts.
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		long long n, r;
		cin >> n >> r;
		Solution obj;
		int ans = obj.nCr(n, r);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends