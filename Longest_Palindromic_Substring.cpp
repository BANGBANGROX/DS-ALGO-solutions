//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    string longestPalindrome(string s) {
        // code here 
        int n = s.size();
        int start = 0;
        int maxLength = 0;
        vector<vector<bool>> dp(n, vector<bool>(n));

        for (int len = 1; len <= n; ++len) {
            for (int i = 0; i + len <= n; ++i) {
                int j = i + len - 1;
                if (len == 1) {
                    dp[i][j] = true;
                }
                else if (len == 2) {
                    dp[i][j] = (s[i] == s[j]);
                }
                else {
                    dp[i][j] = (s[i] == s[j]) && dp[i + 1][j - 1];
                }
                if (dp[i][j] && len > maxLength) {
                    maxLength = len;
                    start = i;
                }
            }
        }

        return s.substr(start, maxLength);
    }
};

//{ Driver Code Starts.



int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.longestPalindrome(S) << endl;
    }
    return 0;
}

// } Driver Code Ends