//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    typedef long long ll;

    const int MOD = (int) 1e9 + 7;

    ll binExp(ll a) {
        ll res = 1;
        ll b = MOD - 2;

        while (b > 0) {
            if ((b & 1) > 0) {
                res = (res * a) % MOD;
                --b;
            }
            a = (a * a) % MOD;
            b >>= 1;
        }

        return res;
    }

public:
    int compute_value(int n) {
        // Code here
        vector<ll> factorial(2 * n + 1);

        factorial[0] = 1;

        for (int i = 1; i <= 2 * n; ++i) {
            factorial[i] = (factorial[i - 1] * i) % MOD;
        }

        ll val1 = factorial[2 * n];
        ll val2 = factorial[n];
        ll val3 = binExp(val2);
        ll val4 = (val3 * val3) % MOD;
        ll ans = (val1 * val4) % MOD;

        return (int) ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.compute_value(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends