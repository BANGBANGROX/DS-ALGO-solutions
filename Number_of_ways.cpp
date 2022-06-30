// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
    typedef long long int ll;
public:
    ll arrangeTiles(int n) {
        // code here
        ll a = 1;
        ll b = 1;
        ll c = 1;
        ll d = 1;

        for (int i = 4; i <= n; ++i) {
            ll e = a + d;
            a = b;
            b = c;
            c = d;
            d = e;
        }

        return d;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        Solution ob;
        cout << ob.arrangeTiles(N) << "\n";
    }
    return 0;
}  // } Driver Code Ends