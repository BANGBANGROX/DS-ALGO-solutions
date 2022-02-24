// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int optimalSearchTree(int keys[], int freq[], int n) {
        // code here
        vector<vector<int>> dp(n, vector<int>(n));

        for (int i = 0; i < n; ++i) {
            dp[i][i] = freq[i];
        }

        for (int i = 1; i < n; ++i) {
            freq[i] += freq[i - 1];
        }

        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = len + i - 1;
                int sum = freq[j] - (i > 0 ? freq[i - 1] : 0);
                dp[i][j] = INT_MAX;
                for (int r = i; r <= j; ++r) {
                    dp[i][j] = min(dp[i][j], (r > i ? dp[i][r - 1] : 0) + (r < j ? dp[r + 1][j] : 0));
                }
                dp[i][j] += sum;
            }
        }

        return dp[0][n - 1];
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int* keys = new int[n];
        for (int i = 0; i < n; i++)cin >> keys[i];
        int* freq = new int[n];
        for (int i = 0; i < n; i++)cin >> freq[i];
        Solution ob;
        cout << ob.optimalSearchTree(keys, freq, n) << endl;
    }
    return 0;
}  // } Driver Code Ends