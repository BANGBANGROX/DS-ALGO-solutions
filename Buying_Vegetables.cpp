//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
    int minCostUtil(int n, vector<int> cost[], vector<vector<int>> dp) {
         for (int i = 1; i < n; ++i) {
             int val1 = min(dp[i - 1][0], dp[i - 1][1]);
             int val2 = min(dp[i - 1][1], dp[i - 1][2]);
             int val3 = min(dp[i - 1][0], dp[i - 1][2]);
             dp[i][0] = (val2 == INT_MAX ? INT_MAX : val2 + cost[i][0]);
             dp[i][1] = (val3 == INT_MAX ? INT_MAX : val3 + cost[i][1]);
             dp[i][2] = (val1 == INT_MAX ? INT_MAX : val1 + cost[i][2]);
         }

         return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }

public:
    int minCost(int n, vector<int> cost[]) {
        // code here
        vector<vector<int>> dp(n, vector<int>(3, INT_MAX));

        dp[0][0] = cost[0][0];
        int val1 = minCostUtil(n, cost, dp);
        dp[0][0] = INT_MAX;

        dp[0][1] = cost[0][1];
        int val2 = minCostUtil(n, cost, dp);
        dp[0][1] = INT_MAX;

        dp[0][2] = cost[0][2];
        int val3 = minCostUtil(n, cost, dp);
        dp[0][2] = INT_MAX;

        return min({val1, val2, val3});
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> cost[N];
        int x, y, z;
        for (int i = 0; i < N; i++) {
            cin >> x >> y >> z;
            cost[i].push_back(x);
            cost[i].push_back(y);
            cost[i].push_back(z);
        }

        Solution ob;
        cout << ob.minCost(N, cost) << "\n";
    }
    return 0;
}
// } Driver Code Ends