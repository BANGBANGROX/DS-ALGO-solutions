// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    const int inf = 1e9;
public:
    int minCoins(int coins[], int M, int V) {
        // Your code goes here
        vector<int> dp(V + 1,inf);

        dp[0] = 0;

        for (int i = 0; i < M; ++i) {
            for (int sum = 1; sum <= V; ++sum) {
                if (coins[i] > sum || dp[sum-coins[i]] == inf) continue;
                dp[sum] = min(dp[sum], 1 + dp[sum - coins[i]]);
            }
        }

        return dp[V] == inf ? -1 : dp[V];
    }
};

// { Driver Code Starts.
int main()
{


    int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int* coins = new int[m];
        for (int i = 0; i < m; i++)
            cin >> coins[i];


        Solution ob;
        cout << ob.minCoins(coins, m, v) << "\n";

    }
    return 0;
}
// } Driver Code Ends
