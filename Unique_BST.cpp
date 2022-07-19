//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    typedef long long ll;

    const int mod = 1e9 + 7;

    int binExp(ll a, ll b) {
        ll res = 1;

        while (b > 0) {
            if ((b & 1) > 0) {
                res = (res * a) % mod;
                --b;
            }
            a = (a * a) % mod;
            b /= 2;
        }

        return res;
    }

public:
    //Function to return the total number of possible unique BST. 
    int numTrees(int n) {
        // Your code here
        vector<int> factorial(2 * n + 1);

        factorial[0] = 1;

        for (int i = 1; i <= 2 * n; ++i) {
            factorial[i] = (factorial[i - 1] * (ll)i) % mod;
        }


        ll a = factorial[2 * n];
        ll b = binExp(factorial[n], (ll)mod - 2);
        ll c = binExp((ll)n + 1, (ll)mod - 2);
        ll val1 = (a * b) % mod;
        ll val2 = (val1 * b) % mod;
        ll ans = (val2 * c) % mod;

        return (int)ans;
    }
};

//{ Driver Code Starts.
#define mod (int)(1e9+7)
int main() {

    //taking total testcases
    int t;
    cin >> t;
    while (t--) {

        //taking total number of elements
        int n;
        cin >> n;
        Solution ob;
        //calling function numTrees()
        cout << ob.numTrees(n) << "\n";
    }
}
// } Driver Code Ends
// } Driver Code Ends