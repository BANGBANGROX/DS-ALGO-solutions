//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    vector<vector<int>> dp;

    int maxAmountUtil(int l, int r, int coins[]) {
         if (l > r) return 0;

         if (l == r) return coins[l];

         if (dp[l][r] != INT_MAX) return dp[l][r];

         return dp[l][r] = max(coins[l] - maxAmountUtil(l + 1, r, coins), coins[r] -
         maxAmountUtil(l, r - 1, coins));
    }

public:
    int maxAmount(int coins[], int n) {
        // Your code goes here
        dp = vector<vector<int>>(n, vector<int>(n, INT_MAX));
        int totalSum = accumulate(coins, coins + n, 0);
        int difference = maxAmountUtil(0, n - 1, coins);

        return (totalSum + difference) / 2;
    }
};

//{ Driver Code Starts.
int main()
{


    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
            cin >> a[i];



        Solution ob;
        cout << ob.maxAmount(a, n) << "\n";


    }
    return 0;
}

// } Driver Code Ends