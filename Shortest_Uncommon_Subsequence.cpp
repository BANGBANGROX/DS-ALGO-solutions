// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int shortestUnSub(string s, string t) {
        // code here
        int m = s.size();
        int n = t.size();
        const int inf = 1e9;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, inf));

        for (int i = 1; i <= m; ++i) {
            dp[i][0] = 1;
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int k = j;
                for (; k >= 0; --k) {
                    if (s[i] == t[k]) break;
                }
                if (k < 0) dp[i + 1][j + 1] = 1;
                else dp[i + 1][j + 1] = min(dp[i][j + 1], dp[i][k] + 1);
            }
        }

        return dp[m][n] >= inf ? -1 : dp[m][n];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S, T;
        cin >> S >> T;

        Solution ob;
        cout << ob.shortestUnSub(S, T) << endl;
    }
    return 0;
}  // } Driver Code Ends