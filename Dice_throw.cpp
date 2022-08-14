//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    typedef long long ll;
public:
    ll noOfWays(int m, int n ,int x) {
        // code here
        vector<vector<ll>> dp(n + 1, vector<ll>(x + 1));

        dp[0][0] = 1;

        for (int i = 1; i <= n; ++i) {
            for (int j = i; j <= x; ++j) {
                for (int k = 1; k <= j; ++k) {
                   dp[i][j] += dp[i - 1][j - k];
                }
            }
        }

        return dp[n][x];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int M,N,X;

        cin>>M>>N>>X;

        Solution ob;
        cout << ob.noOfWays(M,N,X) << endl;
    }
    return 0;
}
// } Driver Code Ends