//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    vector<vector<int>> dp;
    int m;
    int n;

    int wildCard(string pattern, string s, int i, int j) {
        if (i == m) return j == n;

        if (j == n) return dp[i][j] = (pattern[i] == '*' && wildCard(pattern, s, i + 1, j));

        if (dp[i][j] != -1) return dp[i][j];

        if (pattern[i] == '?') {
            return dp[i][j] = wildCard(pattern, s, i + 1, j + 1);
        }

        else if (pattern[i] == '*') {
            return dp[i][j] = wildCard(pattern, s, i, j + 1) || 
                wildCard(pattern, s, i + 1, j + 1) || wildCard(pattern, s, i + 1, j);
        }

        return dp[i][j] = (pattern[i] == s[j] && wildCard(pattern, s, i + 1, j + 1));
    }

public:
    /*You are required to complete this method*/
    int wildCard(string pattern, string s) {
        m = pattern.size();
        n = s.size();

        dp = vector<vector<int>>(m + 1, vector<int>(n + 1, -1));

        return wildCard(pattern, s, 0, 0);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string pat, text;
        cin >> pat;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> text;
        Solution obj;
        cout << obj.wildCard(pat, text) << endl;
    }
}

// } Driver Code Ends