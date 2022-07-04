// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++


class Solution {
    typedef long long ll;

    const int MOD = 1e9 + 7;

    ll binExp(ll a, ll b) {
        ll res = 1;

        while (b > 0) {
            if ((b & 1) > 0) {
                res = ((res % MOD) * (a % MOD)) % MOD;
                --b;
            }
            a = ((a % MOD) * (a % MOD)) % MOD;
            b /= 2;
        }

        return res;
    }

public:
    int permutationCoeff(int n, int k) {
        //Code here
        vector<ll> factorial(n + 1);

        factorial[0] = 1;

        for (int i = 1; i <= n; ++i) {
            factorial[i] = (factorial[i - 1] * i) % MOD;
        }

        return (factorial[n] * binExp(factorial[n - k], MOD - 2)) % MOD;
    }
};


// { Driver Code Starts.



int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        Solution ob;
        int ans = ob.permutationCoeff(n, k);
        cout << ans << endl;
    }
}  // } Driver Code Ends