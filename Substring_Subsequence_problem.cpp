// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int getLongestSubsequence(string s, string t) {
        // code here
        int m = s.size();
        int n = t.size();
        int ans = 0;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = dp[i - 1][j];
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = max(dp[i - 1][j - 1] + 1, dp[i - 1][j]);
                }
                ans = max(ans, dp[i][j]);
            }
        }

        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string A, B;

        cin >> A >> B;

        Solution ob;
        cout << ob.getLongestSubsequence(A, B) << endl;
    }
    return 0;
}  // } Driver Code Ends