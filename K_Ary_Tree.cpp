// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    typedef long long ll;

public:
    ll karyTree(int k, int m) {
        // code here
        const int mod = 1e9 + 7;
        ll ans = 1;

        while (m > 0) {
            if ((m & 1) > 0) {
                ans = ((ans % mod) * ((ll)k % mod)) % mod;
                --m;
            }
            k = ((k % mod) * ((ll)k % mod)) % mod;
            m /= 2;
        }

        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int k, m;

        cin >> k >> m;

        Solution ob;
        cout << ob.karyTree(k, m) << endl;
    }
    return 0;
}  // } Driver Code Ends