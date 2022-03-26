// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    int findMinInsertions(string s) {
        // code here 
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));

        for (int len = 1; len < n; ++len) {
            for (int l = 0, h = len; h < n; ++l, ++h) {
                dp[l][h] = (s[l] == s[h]) ? dp[l + 1][h - 1] : 
                    min(dp[l + 1][h], dp[l][h - 1]) + 1;
            }
        }

        return dp[0][n - 1];
    }
};

// { Driver Code Starts.



int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.findMinInsertions(S) << endl;
    }
    return 0;
}
// } Driver Code Ends