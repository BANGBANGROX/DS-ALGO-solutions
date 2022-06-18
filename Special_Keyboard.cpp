// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
    typedef long long int ll;
public:
    ll optimalKeys(int n) {
        // code here
        vector<ll> dp(n + 1);

        for (int i = 0; i <= n; ++i) {
            dp[i] = i;
            for (int j = 1; j <= i - 3; ++j) {
                dp[i] = max(dp[i], dp[j] * ((ll)i - j - 1));
            }
        }

        return dp[n];
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
        cout << ob.optimalKeys(N) << "\n";
    }
    return 0;
}  // } Driver Code Ends