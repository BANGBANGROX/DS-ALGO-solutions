//{ Driver Code Starts
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
public:
    int distinctSubsequences(string s) {
        // Your code goes here
        const int MOD = (int)1e9 + 7;
        int n = (int)s.size();
        vector<int> dp(n + 1);
        unordered_map<char, int> index;

        dp[0] = 1;

        for (int i = 1; i <= n; ++i) {
            char ch = s[i - 1];
            dp[i] = (dp[i - 1] * 2) % MOD;
            if (index.find(ch) != index.end()) {
                int idx = index[ch];
                dp[i] = (dp[i] - dp[idx - 1] + MOD) % MOD;
            }
            index[ch] = i;
        }

        return dp[n];
    }
};

//{ Driver Code Starts.

int main()
{


    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.distinctSubsequences(s) << "\n";
    }

    return 0;
}
// } Driver Code Ends