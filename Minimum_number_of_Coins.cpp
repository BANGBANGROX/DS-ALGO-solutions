// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    vector<int> minPartition(int target) {
        // code here
        vector<int> coins = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 };
        vector<int> dp(target + 1, INT_MAX);
        vector<int> index(target + 1, -1);
        vector<int> ans;

        dp[0] = 0;

        for (int i = 0; i < (int)coins.size(); ++i) {
            for (int sum = 1; sum <= target; ++sum) {
                if (sum < coins[i]) continue;
                if (dp[sum] > 1 + dp[sum - coins[i]]) {
                    dp[sum] = 1 + dp[sum - coins[i]];
                    index[sum] = i;
                }
            }
        }

        while (index[target] != -1) {
            ans.push_back(coins[index[target]]);
            target -= coins[index[target]];
        }

        return ans;
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
        vector<int> numbers = ob.minPartition(N);
        for (auto u : numbers)
            cout << u << " ";
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends